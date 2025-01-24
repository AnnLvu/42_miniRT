# **miniRT** 🌟

**MiniRT** is a ray tracing program 🖥️ designed to generate stunning 3D images from scenes described in `.rt` files. This project brings together geometry, lighting, and interactivity to deliver realistic rendered images. 🎨✨

---

## **🚀 Features**
- **🌐 Geometric Objects**: Render planes, spheres, and cylinders with precision.
- **💡 Lighting**: Realistic effects with ambient and diffuse lighting, hard shadows, and spot brightness.
- **🛠️ Transformations**:
  - Translate, rotate, and resize objects for complete scene control.
  - Adjust cameras and lights for dynamic perspectives.
- **📜 Scene Description**:
  - Simple `.rt` file format for scene configuration.
  - Handles invalid configurations with clear error messages.
- **🖼️ Real-Time Display**:
  - Rendered scenes are displayed in a **MiniLibX** window.
  - Fluid interactions with real-time updates.

---

## **🎮 Controls**

### **Camera** 🎥
- **Rotate**: `W`, `S`, `A`, `D`, `E`, `F`
- **Translate**: Arrow keys (`↑`, `↓`, `→`, `←`), `+`, `-`

### **Objects** 🔧
1. **Select Object**: Click on it with the **left mouse button**.
2. **Rotate**:
   - **X-axis**: `X`
   - **Y-axis**: `Y`
   - **Z-axis**: `Z`
3. **Translate**: `I`, `K`, `J`, `L`, `U`, `H`
4. **Resize**:
   - **Increase**: `1`
   - **Decrease**: `2`

### **Light** 💡
- **Translate**: `M`, `N`, `O`, `P`, `B`, `C`

### **Exit** 🚪
- **ESC**: Close the program.
- **Red Cross Button**: Exit via the window frame.

---

## **📝 Scene File Format (`.rt`)**

The scene file describes all elements of the scene with specific identifiers and attributes. Here’s an example:

```plaintext
A 0.2 255,255,255
C -50,0,20 0,0,1 70
L -40,0,30 0.7 255,255,255
pl 0,0,0 0,1.0,0 255,0,225
sp 0,0,20 20 255,0,0
cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
```

## 🖼️ Example Scenes  

### 🌟 Sphere with Light  
This scene demonstrates how a single light source interacts with a sphere.  

![Sphere with Light](images/sphere_with_light.png)  

### 🌀 Cylinder Scene  
This scene shows a cylinder with proper lighting and shadow rendering.  

![Cylinder Scene](images/cylinder_scene.png)  

### 🌄 Plane and Sphere  
A minimalistic scene featuring a plane and a sphere with ambient lighting.  

![Plane and Sphere](images/plane_and_sphere.png)  

### 🔥 Complex Scene 1  
A detailed scene with multiple objects, showcasing translation and rotation.  

![Complex Scene 1](images/complex_scene_1.png)  

### 🌌 Complex Scene 2  
A full-fledged scene with cylinders, planes, and advanced lighting effects.  

![Complex Scene 2](images/complex_scene_2.png)  

---

## 🚀 Getting Started  

1. Clone this repository:  
   ```bash
   git clone git@github.com:git@github.com:AnnLvu/42_miniRT.git
   cd miniRT
   ```

2. Compile the program using `make`:
   ```bash
   make
   ```
3. Run the program with a .rt scene file:
    ```bash
   ./miniRT file_rt/example.rt
   ```

