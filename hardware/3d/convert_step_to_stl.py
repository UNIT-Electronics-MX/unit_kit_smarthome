#!/usr/bin/env python3
"""
Convert STEP files to STL format
Usage: python convert_step_to_stl.py input.step output.stl [tolerance]
"""
import sys
import cadquery as cq

def convert_step_to_stl(input_file, output_file, tolerance=0.1):
    """
    Convert STEP file to STL
    
    Args:
        input_file: Path to input STEP file
        output_file: Path to output STL file
        tolerance: Mesh tolerance (lower = more detail, larger file)
                   0.01 = high detail, 0.5 = simplified
    """
    print(f"Loading {input_file}...")
    mesh = cq.importers.importStep(input_file)
    
    print(f"Exporting to {output_file} (tolerance={tolerance})...")
    cq.exporters.export(
        mesh,
        output_file,
        tolerance=tolerance,
        angularTolerance=0.1
    )
    
    print(f"✓ Conversion completed: {output_file}")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python convert_step_to_stl.py input.step output.stl [tolerance]")
        print("Example: python convert_step_to_stl.py model.step model.stl 0.5")
        sys.exit(1)
    
    input_file = sys.argv[1]
    output_file = sys.argv[2]
    tolerance = float(sys.argv[3]) if len(sys.argv) > 3 else 0.1
    
    convert_step_to_stl(input_file, output_file, tolerance)
