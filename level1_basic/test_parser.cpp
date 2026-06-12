// Usa Google Test

#include <gtest/gtest.h>
#include "config_parser.h"

// ESEMPIO PROFESSORE:
TEST(ConfigParserTest, ParseValidLine) {
    ConfigPair* pair = ParseConfigLine("host=localhost");
    
    // Usiamo ASSERT_NE perche' se pair e' null, dereferenziarlo crasherà il test
    ASSERT_NE(pair, nullptr) << "Il parsing di una linea valida non deve restituire null";
    
    // Usiamo EXPECT_EQ per controllare i valori senza interrompere subito in caso di errore
    EXPECT_EQ(pair->key, "host");
    EXPECT_EQ(pair->value, "localhost");
    
    delete pair; // Clean-up (come mostrato nelle slide)
}

// TODO STUDENTE 1: Testa cosa succede se la linea non contiene il carattere '=' (es. "invalidline")
// Assicurati che restituisca nullptr. Aggiungi un messaggio personalizzato in caso di fallimento.
TEST(ConfigParserTest, ParseLineWithoutEqualsSignReturnsNull) {
    ConfigPair* pair = ParseConfigLine("linewithnoequalsign");

    EXPECT_EQ(pair, nullptr) << "Il parsing senza "=" deve restituire null";

    delete pair;
}

// TODO STUDENTE 2: Testa il parsing di una linea vuota "".
TEST(ConfigParserTest, ParseEmptyLineReturnsNull) {
    ConfigPair* pair = ParseConfigLine("");
    EXPECT_EQ(pair, nullptr) << "Il parsing di una linea valida non deve restituire null";
    delete pair;
}

// TODO STUDENTE 3: La funzione IsValidKeyName accetta solo lettere e numeri.
// Scrivi un test che verifichi almeno 3 casi validi e 3 casi non validi 
// (es. stringhe con spazi, caratteri speciali). Usa EXPECT_EQ confrontando con true/false.
TEST(KeyValidationTest, ValidatesKeyCharactersCorrectly) {

    // 3 valid cases:
    EXPECT_EQ(IsValidKeyName("ciao1"), true);
    EXPECT_EQ(IsValidKeyName("ciao2"), true);
    EXPECT_EQ(IsValidKeyName("ciao3"), true);

    // 3 not valid cases:
    EXPECT_EQ(IsValidKeyName("ciao!"), false);
    EXPECT_EQ(IsValidKeyName("ciao-"), false);
    EXPECT_EQ(IsValidKeyName("ciao_%"), false);
}