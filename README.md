

---

### **Sensor Simulation & Visualization**  

#### 📌 **Overview**  
This project simulates four types of thermal sensors, logs temperature readings, and applies a threshold-based control system (Fan ON/OFF, Heater ON/OFF). A Python script visualizes the data with graphs.  

---

### **📂 Project Files**  
- `main.c` → C program for sensor simulation  
- `thermoelectric.h`, `thermoresistive.h`, `thermo_optical.h`, `thermo_acoustic.h` → Header files for sensors  
- `thresholds.h` → Defines Fan/Heater control logic  
- `data.csv` → Sensor readings log  
- `visualize.py` → Python script for plotting temperature trends  

---

### **🚀 How to Run**  

#### **1️⃣ Run the C Program (Generates Sensor Data)**
```bash
gcc main.c -o sensor_simulation
./sensor_simulation
```
✔ Generates `data.csv` with sensor readings  

#### **2️⃣ Run the Python Script (Visualizes Data)**
```bash
python visualize.py
```
✔ Displays temperature trends and system actions  

---

### **📌 Features**  
✅ Simulates realistic temperature sensors  
✅ Applies threshold-based Fan/Heater control  
✅ Logs data to CSV for analysis  
✅ Visualizes data trends in Python  

---

### **👨‍💻 Created by Raghav Nayyar**  

