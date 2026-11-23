import matplotlib.pyplot as plt
import numpy as np

triangle = np.array([[1, 1], [4, 1], [2, 3]])

tx, ty = 3, 2

translated_triangle = triangle + np.array([tx, ty])

print("Original Vertices:\n", triangle)
print("Translated Vertices:\n", translated_triangle)


def plot_shapes(orig, trans, title):
    orig_closed = np.vstack([orig, orig[0]])
    trans_closed = np.vstack([trans, trans[0]])
    plt.figure(figsize=(6, 6))
    plt.plot(
        orig_closed[:, 0], orig_closed[:, 1], "b--o", label="Original"
    )
    plt.plot(
        trans_closed[:, 0], trans_closed[:, 1], "r-o", label="Transformed"
    )
    plt.axhline(0, color="black", linewidth=0.8)
    plt.axvline(0, color="black", linewidth=0.8)
    plt.grid(True, linestyle=":")
    plt.legend()
    plt.title(title)
    plt.axis("equal")
    plt.show()


plot_shapes(triangle, translated_triangle, "1. Translation (tx=3, ty=2)")