import matplotlib.pyplot as plt
import numpy as np

triangle = np.array([[1, 1], [4, 1], [2, 3]])

xf, yf = 2, 1
sx, sy = 2, 2

scaled_triangle = []
for x, y in triangle:
    x_new = xf + (x - xf) * sx
    y_new = yf + (y - yf) * sy
    scaled_triangle.append([x_new, y_new])

scaled_triangle = np.array(scaled_triangle)
print("Scaled Vertices:\n", scaled_triangle)

orig_closed = np.vstack([triangle, triangle[0]])
scl_closed = np.vstack([scaled_triangle, scaled_triangle[0]])
plt.figure(figsize=(6, 6))
plt.plot(orig_closed[:, 0], orig_closed[:, 1], "b--o", label="Original")
plt.plot(scl_closed[:, 0], scl_closed[:, 1], "r-o", label="Scaled (sx=2, sy=2)")
plt.scatter(
    [xf], [yf], color="green", s=100, zorder=5, label="Fixed Point (2,1)"
)
plt.axhline(0, color="black", linewidth=0.8)
plt.axvline(0, color="black", linewidth=0.8)
plt.grid(True, linestyle=":")
plt.legend()
plt.title("3. Scaling relative to Fixed Point (2, 1)")
plt.axis("equal")
plt.show()