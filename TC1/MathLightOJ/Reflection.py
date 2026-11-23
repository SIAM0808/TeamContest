import matplotlib.pyplot as plt
import numpy as np

triangle = np.array([[1, 1], [4, 1], [2, 3]])

ones = np.ones((triangle.shape[0], 1))
hom_triangle = np.hstack([triangle, ones]).T  # 3x3 matrix

M_x = np.array([[1, 0, 0], [0, -1, 0], [0, 0, 1]])  # About x-axis
M_y = np.array([[-1, 0, 0], [0, 1, 0], [0, 0, 1]])  # About y-axis
M_origin = np.array([[-1, 0, 0], [0, -1, 0], [0, 0, 1]])  # About origin
M_yx = np.array([[0, 1, 0], [1, 0, 0], [0, 0, 1]])  # About line y = x

reflected_hom = M_x @ hom_triangle
reflected_triangle = reflected_hom[:2, :].T

print("Reflected Vertices (About x-axis):\n", reflected_triangle)

orig_closed = np.vstack([triangle, triangle[0]])
ref_closed = np.vstack([reflected_triangle, reflected_triangle[0]])
plt.figure(figsize=(6, 6))
plt.plot(orig_closed[:, 0], orig_closed[:, 1], "b--o", label="Original")
plt.plot(
    ref_closed[:, 0], ref_closed[:, 1], "r-o", label="Reflected (x-axis)"
)
plt.axhline(0, color="black", linewidth=1.2)
plt.axvline(0, color="black", linewidth=0.8)
plt.grid(True, linestyle=":")
plt.legend()
plt.title("4. Reflection about x-axis")
plt.axis("equal")
plt.show()