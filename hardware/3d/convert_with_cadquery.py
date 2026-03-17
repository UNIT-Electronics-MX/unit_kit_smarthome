#!/usr/bin/env python3
"""Convert STEP file to STL using CadQuery"""
import cadquery as cq

# Import STEP file
print("Importing STEP file...")
result = cq.importers.importStep("/media/mr/firmware/github-mx/4_fase/unit_kit_smarthome/hardware/3d/UE0001.step")

# Export to STL
print("Exporting to STL...")
cq.exporters.export(result, "/media/mr/firmware/github-mx/4_fase/unit_kit_smarthome/hardware/3d/UE0001.stl")

print("✓ Conversion completed: UE0001.stl")
