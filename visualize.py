import pandas as pd
import matplotlib.pyplot as plt

# Define thresholds
FAN_ON_THRESHOLD = 35.0
HEATER_ON_THRESHOLD = 6.0

# Read the CSV file
df = pd.read_csv("sensor_data.csv")

# Create a plot
plt.figure(figsize=(12, 6))

# Plot individual sensor readings
plt.plot(df["Reading"], df["Thermoelectric"], label="Thermoelectric", linestyle="dashed", alpha=0.7)
plt.plot(df["Reading"], df["Thermoresistive"], label="Thermoresistive", linestyle="dashed", alpha=0.7)
plt.plot(df["Reading"], df["Thermo-Optical"], label="Thermo-Optical", linestyle="dashed", alpha=0.7)
plt.plot(df["Reading"], df["Thermo-Acoustic"], label="Thermo-Acoustic", linestyle="dashed", alpha=0.7)

# Plot the average temperature
plt.plot(df["Reading"], df["Average"], label="Average Temperature", linewidth=2, color="black")

# Highlight Fan ON/OFF and Heater ON/OFF regions
for i in range(len(df)):
    if df["Action"][i] == "Fan ON":
        plt.axvline(x=i, color="red", alpha=0.1)
    elif df["Action"][i] == "Heater ON":
        plt.axvline(x=i, color="blue", alpha=0.1)

# Add threshold lines
plt.axhline(y=FAN_ON_THRESHOLD, color="red", linestyle="--", label="Fan ON Threshold (35°C)")
plt.axhline(y=HEATER_ON_THRESHOLD, color="blue", linestyle="--", label="Heater ON Threshold (6°C)")

# Labels and title
plt.xlabel("Time (Readings)")
plt.ylabel("Temperature (°C)")
plt.title("Temperature Sensor Readings Over Time")
plt.legend()
plt.grid(True)

# Show plot
plt.show()
