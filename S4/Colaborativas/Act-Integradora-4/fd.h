void imprimir() const {
        for (const auto& par : nodos) {
            par.second->print();
        }
    }

    void imprimirGrados() const {
        for (const auto& par : nodos) {
            par.second->printGrado();
        }
    }