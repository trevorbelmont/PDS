#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "dicionario.h"

#include "doctest.h"

TEST_CASE("Testa Dicionario::tamanho()") {
    Dicionario d;
    // CHECK: d.tamanho()
    CHECK(d.tamanho() == 0);

    d.Inserir("c1", "v1");
    // CHECK: d.tamanho()
    CHECK(d.tamanho() == 1);

    d.Inserir("c2", "v2");
    // CHECK: d.tamanho()
    CHECK(d.tamanho() == 2);
}

TEST_CASE("Testa Dicionario::pertence(chave)") {
    Dicionario d;

    // CHECK: d.pertence("c1")
    CHECK_FALSE(d.pertence("c1"));

    // CHECK: d.pertence("c2")
    CHECK_FALSE(d.pertence("c2"));

    d.Inserir("c1", "v1");
    // CHECK: d.pertence("c1")
    // CHECK: d.pertence("c2")
    CHECK(d.pertence("c1"));
    CHECK_FALSE(d.pertence("c2"));

    d.Inserir("c2", "v2");
    // CHECK: d.pertence("c1")
    // CHECK: d.pertence("c2")
    CHECK(d.pertence("c1"));
    CHECK(d.pertence("c2"));
}

TEST_CASE("Testa Dicionario::menor()") {
    Dicionario d;
    d.Inserir("c3", "v3");
    // CHECK: d.menor()
    CHECK(d.menor() == "c3");

    d.Inserir("c2", "v2");
    // CHECK: d.menor()
    CHECK(d.menor() == "c2");

    d.Inserir("c1", "v1");
    // CHECK: d.menor()
    CHECK(d.menor() == "c1");

    d.Inserir("c4", "v4");
    // CHECK: d.menor()
    CHECK(d.menor() == "c1");
}

TEST_CASE("Testa Dicionario::valor(chave)") {
    Dicionario d;
    d.Inserir("c3", "v3");
    d.Inserir("c2", "v2");
    d.Inserir("c1", "v1");
    d.Inserir("c4", "v4");
    CHECK(d.valor("c1") == "v1");  // CHECK: d.valor("c1")
    CHECK(d.valor("c2") == "v2");  // CHECK: d.valor("c2")
    CHECK(d.valor("c3") == "v3");  // CHECK: d.valor("c3")
    CHECK(d.valor("c4") == "v4");  // CHECK: d.valor("c4")
}

TEST_CASE("Testa Dicionario::Inserir(chave, valor)") {
    Dicionario d;

    d.Inserir("c2", "v2");

    CHECK(d.pertence("c2") == true);  // CHECK: d.pertence("c2")
    CHECK(d.valor("c2") == "v2");     // CHECK: d.valor("c2")
    CHECK(d.tamanho() == 1);          // CHECK: d.tamanho()

    d.Inserir("c3", "v3");

    CHECK(d.pertence("c3") == true);  // CHECK: d.pertence("c3")
    CHECK(d.valor("c3") == "v3");     // CHECK: d.valor("c3")
    CHECK(d.tamanho() == 2);          // CHECK: d.tamanho()

    d.Inserir("c1", "v1");
    CHECK(d.pertence("c1") == true);  // CHECK: d.pertence("c1")
    CHECK(d.valor("c1") == "v1");     // CHECK: d.valor("c1")
    CHECK(d.tamanho() == 3);          // CHECK: d.tamanho()
}

TEST_CASE("Testa Dicionario::Remover(chave)") {
    Dicionario d;

    d.Inserir("c3", "v3");
    d.Inserir("c2", "v2");
    d.Inserir("c1", "v1");
    d.Inserir("c4", "v4");

    d.Remover("c2");
    CHECK(d.pertence("c2") == false);  // CHECK: d.pertence("c2")
    CHECK(d.tamanho() == 3);           // CHECK: d.tamanho()

    d.Remover("c3");
    // CHECK: !d.pertence("c3"         // CHECK: d.tamanho()
    CHECK(d.pertence("c3") == false);
    CHECK(d.tamanho() == 2);

    d.Remover("c1");
    // CHECK: d.pertence("c1"          // CHECK: d.tamanho()
    CHECK(d.pertence("c1") == false);
    CHECK(d.tamanho() == 1);
}

TEST_CASE("Testa Dicionario::Alterar(chave, valor)") {
    Dicionario d;
    d.Inserir("c3", "v3");
    d.Inserir("c2", "v2");
    d.Inserir("c1", "v1");
    d.Inserir("c4", "v4");

    d.Alterar("c2", "x2");
    CHECK(d.pertence("c2") == true);  // CHECK: d.pertence("c2")
    CHECK(d.valor("c2") == "x2");     // CHECK: d.valor("c2")
    CHECK(d.tamanho() == 4);          // CHECK: d.tamanho()

    d.Alterar("c3", "x3");
    CHECK(d.pertence("c3") == true);  // CHECK: d.pertence("c3")
    CHECK(d.valor("c3") == "x3");     // CHECK: d.valor("c3")
    CHECK(d.tamanho() == 4);          // CHECK: d.tamanho()

    d.Alterar("c1", "x1");
    CHECK(d.pertence("c1") == true);  // CHECK: d.pertence("c1")
    CHECK(d.valor("c1") == "x1");     // CHECK: d.valor("c1")
    CHECK(d.tamanho() == 4);          // CHECK: d.tamanho()


    CHECK(d.pertence("c4") == true);  // CHECK: d.pertence("c2")
    CHECK(d.valor("c4") == "v4");     // CHECK: d.valor("c2")
    CHECK(d.tamanho() == 4);          // CHECK: d.tamanho()

}
