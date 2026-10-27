# Internship Project Portfolio

This folder collects selected quantitative research and software engineering work completed during an internship. The projects cover market-data workflows, statistical trading strategies, database design, numerical methods, and financial-market research.

## Selected work

- **Pairs trading and statistical arbitrage (Week 1):** Import and store daily stock data, analyze correlations, cluster related stocks, and develop and backtest a mean-reversion strategy. The two task notebooks contain the work by topic; the complete-project notebook brings the Week 1 work together. A summary is included as a slide deck.
- **Intraday data systems (Week 3):** Explore time-series and document databases, a REST API, and query-performance benchmarking.
- **Numerical methods (Week 4):** Implement the power method in C++ and call it from Python to estimate a matrix's largest singular value.
- **Interest-rate markets (Week 5):** Present research on benchmark-rate transitions and interest-rate derivatives.

## Folder structure

```text
internship/
├── README.md
├── week-01-task-01-daily-data-storage.ipynb
├── week-01-task-02-mean-reversion-strategy.ipynb
├── week-01-complete-pairs-trading-project.ipynb
├── week-01-pairs-trading-summary.pptx
├── week-03-intraday-database-benchmarking.ipynb
├── week-04-cpp-power-method.ipynb
├── week-05-interest-rate-benchmarks-and-derivatives.pptx
├── stock-data-import-and-storage.ipynb
├── correlation-and-clustering-analysis.ipynb
├── stock-data-rest-api.ipynb
├── stock-clustering-mean-reversion-framework.ipynb
└── power_method.cpp
```

The supporting notebooks break out data import, correlation analysis, and REST API experiments from the Week 1 work. The clustering framework is an additional strategy prototype. `power_method.cpp` is the C++ source for the Week 4 exercise. Its compiled Python extension is specific to its build environment and is not included. Jupyter checkpoint files, the empty draft notebook, and the saved C++ source backup are working artifacts, not portfolio deliverables.

## Running the notebooks

The notebooks are research and demonstration artifacts, not a single turnkey application. Depending on the notebook, running them may require Python packages, internet access to market-data sources, or a separately configured MongoDB or TimescaleDB instance. MongoDB notebooks that use a remote database read the connection string from the `MONGODB_URI` environment variable; keep credentials out of notebook files. Review each notebook's setup and configuration cells before execution. The Week 4 compiled extension may need to be rebuilt for a different operating system or Python version.
