#!/usr/bin/env python3
"""Fix browser PDF timestamps to the manual date for reproducible builds."""

from datetime import date
from pathlib import Path
import re
import sys


def main() -> None:
    if len(sys.argv) != 3:
        raise SystemExit("usage: normalize-pdf.py DOCUMENT.pdf book.yml")
    document = Path(sys.argv[1])
    book = Path(sys.argv[2])
    match = re.search(r'^date:\s*["\']?(\d{4}-\d{2}-\d{2})', book.read_text(), re.MULTILINE)
    if not match:
        raise ValueError("book.yml needs a YYYY-MM-DD date")
    stamp = date.fromisoformat(match.group(1)).strftime("D:%Y%m%d000000+00'00'").encode()
    pdf = document.read_bytes()
    pdf, count = re.subn(
        rb'/(?:CreationDate|ModDate)\s*\(D:\d{14}[+-]\d{2}\x27\d{2}\x27\)',
        lambda match: match.group(0).split(b'(')[0] + b'(' + stamp + b')',
        pdf,
    )
    if count != 2:
        raise ValueError(f"expected two PDF timestamps, found {count}")
    document.write_bytes(pdf)


if __name__ == "__main__":
    main()
