# 3D Models

This directory contains 3D models for the UNIT Smart Home project.

## Available Models

### UE0001 - Smart Home Structure

<div align="center">
  <a href="UE0002-DualMCU_V2.1.3.stl">
    <img src="https://img.shields.io/badge/View%203D%20Model-STL-blue?style=for-the-badge" alt="View 3D Model">
  </a>
</div>

**Files:**
- [`UE0001_simplified.stl`](UE0001_simplified.stl) (11 MB) - Simplified STL for viewing on GitHub
- [`UE0001.stl`](UE0001.stl) (25 MB) - High-res STL for 3D printing
- [`UE0001.step`](UE0001.step) (41 MB) - STEP format for CAD software editing

> **Note:** Use the simplified version for quick previewing on GitHub. Download the high-resolution STL for 3D printing.

**Format Information:**
- **STL**: Ready for 3D printing, viewable directly on GitHub with interactive 3D viewer
- **STEP**: Editable CAD format for FreeCAD, Fusion 360, SolidWorks, etc.

## Viewing 3D Models

### On GitHub
Click on any `.stl` file to view it with GitHub's built-in 3D viewer. You can:
- Rotate the model by clicking and dragging
- Zoom in/out with mouse wheel
- Pan by holding Shift + click and drag
- Toggle wireframe/surface view

### Local Viewing
- **STL files**: Open with FreeCAD, Blender, MeshLab, or any 3D slicer software
- **STEP files**: Open with FreeCAD, Fusion 360, SolidWorks, or other CAD software

## 3D Printing

The STL files are ready for 3D printing. Recommended settings:
- Layer height: 0.2mm
- Infill: 20%
- Support: As needed depending on model orientation

## Editing Models

To modify the models:
1. Open the `.step` file in your preferred CAD software
2. Make your modifications
3. Export as STEP (for archiving) and STL (for GitHub visualization)

## Converting Between Formats

To convert STEP files to STL, use the provided conversion script:

```bash
# Install required package (first time only)
pip install cadquery

# Convert with default quality
python convert_step_to_stl.py input.step output.stl

# Convert simplified (smaller file for GitHub)
python convert_step_to_stl.py input.step output_simplified.stl 0.5

# Convert high detail (for 3D printing)
python convert_step_to_stl.py input.step output_hires.stl 0.01
```

**Parameters:**
- Lower tolerance (0.01) = more detail, larger file
- Higher tolerance (0.5) = simplified, smaller file

Alternative tools: FreeCAD, Blender, or [CAD Exchanger](https://cadexchanger.com/convert)

---

<div align="center">
  <sub>3D Models for UNIT Smart Home Kit</sub>
</div>
