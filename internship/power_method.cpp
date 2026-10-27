#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include <cmath>

namespace py = pybind11;

// Multiply matrix M (n x n) with vector v (n)
std::vector<double> matvec(
    const std::vector<std::vector<double>>& M,
    const std::vector<double>& v
) {
    int n = M.size();
    std::vector<double> result(n, 0.0);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            result[i] += M[i][j] * v[j];

    return result;
}

// Dot product
double dot(const std::vector<double>& a, const std::vector<double>& b) {
    double s = 0.0;
    for (size_t i = 0; i < a.size(); ++i)
        s += a[i] * b[i];
    return s;
}

// Normalize vector
void normalize(std::vector<double>& v) {
    double norm = std::sqrt(dot(v, v));
    for (double& x : v)
        x /= norm;
}

// Power Method: dominant eigenvalue
double power_method(
    const std::vector<std::vector<double>>& M,
    int max_iters = 1000,
    double tol = 1e-6
) {
    int n = M.size();
    std::vector<double> v(n, 1.0);
    normalize(v);

    double lambda_old = 0.0;

    for (int i = 0; i < max_iters; ++i) {
        auto w = matvec(M, v);
        normalize(w);

        double lambda = dot(w, matvec(M, w));

        if (std::abs(lambda - lambda_old) < tol)
            return lambda;

        v = w;
        lambda_old = lambda;
    }

    return lambda_old;
}

PYBIND11_MODULE(power_method_cpp, m) {
    m.def("power_method", &power_method,
          "Compute dominant eigenvalue using power method");
}
