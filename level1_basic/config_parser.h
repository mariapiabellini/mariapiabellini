//.h = file header, contiene info che possono essere usate dagli altri

#pragma once
#include <string>

struct ConfigPair {
    std::string key;
    std::string value;
};

// Se la stringa e' valida ("chiave=valore"), alloca dinamicamente un ConfigPair.
// Altrimenti ritorna nullptr. Il chiamante deve fare delete.
ConfigPair* ParseConfigLine(const std::string& line);
bool IsValidKeyName(const std::string& key);
// Controlla se una chiave contiene solo lettere e numeri.