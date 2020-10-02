# ICLR2021 - On the Effectiveness of Weight-Encoded Neural Implicit 3D Shapes
A neural implicit outputs a number indicating whether the given query point in space is outside, inside, or on a surface. Many prior works have focused on _latent-encoded_ neural implicits, where latent vector encoding a specific shape is also fed as input. While affording latent-space interpolation, this comes at the cost of reconstruction accuracy for any _single_ shape.  Training a specific network for each 3D shape, a _weight-encoded_ neural implicits may forgo the latent vector and focus reconstruction accuracy on the details of a single shape. While previously considered as intermediary representation 3D scanning tasks or as a toy-problem leading up to latent-encoding tasks, weight-encoded neural implicits have not yet been taken seriously as a 3D shape representation. In this paper, we establish that weight-encoded neural implicits meet the criteria of a first-class 3D shape representation. We introduce a suite of technical contributions to improve reconstruction accuracy, convergence, and robustness when learning the signed distance field induced by a polygonal mesh --- the _de facto_ standard representation. Viewed as a lossy compression, our conversion outperforms standard techniques from geometry processing. Compared to previous latent- and weight-encoded neural implicits we demonstrate superior robustness, accuracy, scalability, and performance.
