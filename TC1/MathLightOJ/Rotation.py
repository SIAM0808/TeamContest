import matplotlib.pyplot as plt
import numpy as np

triangle = np.array([[1, 1], [4, 1], [2, 3]])

xr, yr = 2, 1
theta_deg = 90
theta = np.radians(theta_deg)

cos_t = np.cos(theta)
sin_t = np.sin(theta)

rotated_triangle = []
for x, y in triangle:
    x_new = xr + (x - xr) * cos_t - (y - yr) * sin_t
    y_new = yr + (x - xr) * sin_t + (y - yr) * cos_t
    rotated_triangle.append([x_new, y_new])

rotated_triangle = np.round(np.array(rotated_triangle), 2)
print("Rotated Vertices (Pivot 2,1, Angle 90°):\n", rotated_triangle)

orig_closed = np.vstack([triangle, triangle[0]])
rot_closed = np.vstack([rotated_triangle, rotated_triangle[0]])
plt.figure(figsize=(6, 6))
plt.plot(orig_closed[:, 0], orig_closed[:, 1], "b--o", label="Original")
plt.plot(rot_closed[:, 0], rot_closed[:, 1], "r-o", label="Rotated (90°)")
plt.scatter([xr], [yr], color="green", s=100, zorder=5, label="Pivot (2,1)")
plt.axhline(0, color="black", linewidth=0.8)
plt.axvline(0, color="black", linewidth=0.8)
plt.grid(True, linestyle=":")
plt.legend()
plt.title("2. Rotation about Pivot (2, 1)")
plt.axis("equal")
plt.show()