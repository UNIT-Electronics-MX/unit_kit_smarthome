#!/usr/bin/env python3
"""Use the manual date in DOCX metadata so repeated builds are identical."""

from datetime import date
from pathlib import Path
import re
import sys
from tempfile import NamedTemporaryFile
from zipfile import ZipFile


def main() -> None:
    if len(sys.argv) != 3:
        raise SystemExit("usage: normalize-docx.py DOCUMENT.docx book.yml")
    document = Path(sys.argv[1])
    book = Path(sys.argv[2])
    match = re.search(r'^date:\s*["\']?(\d{4}-\d{2}-\d{2})', book.read_text(), re.MULTILINE)
    if not match:
        raise ValueError("book.yml needs a YYYY-MM-DD date")
    timestamp = f"{date.fromisoformat(match.group(1))}T00:00:00Z"

    with NamedTemporaryFile(dir=document.parent, suffix=".docx", delete=False) as tmp:
        temporary = Path(tmp.name)
    try:
        with ZipFile(document) as source, ZipFile(temporary, "w") as target:
            for info in source.infolist():
                payload = source.read(info.filename)
                if info.filename == "docProps/core.xml":
                    xml = payload.decode("utf-8")
                    xml, count = re.subn(
                        r'(<dcterms:(?:created|modified)\b[^>]*>)[^<]*(</dcterms:(?:created|modified)>)',
                        lambda match: match.group(1) + timestamp + match.group(2),
                        xml,
                    )
                    if count != 2:
                        raise ValueError("DOCX creation and modification dates not found")
                    payload = xml.encode("utf-8")
                info.date_time = (1980, 1, 1, 0, 0, 0)
                target.writestr(info, payload)
        temporary.replace(document)
    finally:
        temporary.unlink(missing_ok=True)


if __name__ == "__main__":
    main()
