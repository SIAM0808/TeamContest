import matplotlib.pyplot as plt
import numpy as np

triangle = np.array([[1, 1], [4, 1], [2, 3]])

sh_x = 2
y_ref = 0

sheared_triangle = []
for x, y in triangle:
    x_new = x + sh_x * (y - y_ref)
    y_new = y
    sheared_triangle.append([x_new, y_new])

sheared_triangle = np.array(sheared_triangle)
print("Sheared Vertices (x-shear, sh_x=2):\n", sheared_triangle)

orig_closed = np.vstack([triangle, triangle[0]])
shr_closed = np.vstack([sheared_triangle, sheared_triangle[0]])
plt.figure(figsize=(7, 5))
plt.plot(orig_closed[:, 0], orig_closed[:, 1], "b--o", label="Original")
plt.plot(
    shr_closed[:, 0], shr_closed[:, 1], "r-o", label="Sheared (x-dir, sh_x=2)"
)
plt.axhline(0, color="black", linewidth=0.8)
plt.axvline(0, color="black", linewidth=0.8)
plt.grid(True, linestyle=":")
plt.legend()
plt.title("5. X-Direction Shear (sh_x = 2)")
plt.axis("equal")
plt.show()