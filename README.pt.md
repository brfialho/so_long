*Este projeto foi criado como parte do currículo da 42 por brfialho.*

---

# So Long - Square Kingdom

Este é um jogo 2D baseado em tiles em que você controla um quadrado. O objetivo é coletar todos os itens do mapa e, em seguida, chegar à saída.
O projeto é dividido em duas versões. A versão básica, que lida com o movimento do jogador, coletáveis e condições de saída. A versão completa, com recursos adicionais de jogabilidade e visuais.

Os recursos da versão completa incluem:
- Inimigos com dois comportamentos: o quadrado verde que se move aleatoriamente e o vermelho que persegue ativamente o jogador
- Sprites feitos a mão, pixel por pixel, e animações
- Contador dinâmico de movimentos exibido na tela

## Uso

### Pré-requisitos

- Compilador **GCC** ou **Clang**
- **GNU Make**
- **Bibliotecas de desenvolvimento do X11** (para Linux)

Em sistemas Debian/Ubuntu, instale as dependências:

```bash
sudo apt-get install libxext-dev libx11-dev
```

### Compilação

Clone o repositório

```bash
git clone --recurse-submodule https://github.com/brfialho/so_long.git
cd so_long
```

Para a versão básica, execute

```bash
make
```

Para a versão completa, execute:

```bash
make bonus
```

### Comandos disponíveis do Make

| Comando       | Descrição                                      |
|---------------|--------------------------------------------------|
| `make`        | Compila a versão minimalista do jogo           |
| `make bonus`        | Compila a versão completa do jogo               |
| `make clean`  | Remove arquivos objeto                           |
| `make fclean` | Remove arquivos objeto e o executável            |
| `make re`     | Recompila do zero                           |

### Executando o programa

Execute o binário compilado com um mapa `.ber` válido:

#### Mapas pré-prontos

Versão básica:
```bash
./so_long maps/mandatory_testing/valid2.ber
```
Versão completa:
```bash
./so_long maps/levels/easy.ber
./so_long maps/levels/medium.ber
./so_long maps/levels/hard.ber
```

#### Criando seu próprio mapa

##### Regras

- O arquivo do mapa deve terminar com `.ber`
- O mapa deve ser cercado por paredes
- O jogador deve conseguir alcançar todos os coletáveis e a saída
- O mapa deve conter apenas os caracteres especificados abaixo

##### Sintaxe

- `1` - Paredes
- `0` - Chão
- `P` - Posição inicial do jogador
- `C` - Coletáveis
- `E` - Saída
- `X` - Inimigo (apenas na versão completa)

Exemplo:

```
111111111111111111
1C010000000C0000C1
100001111100X00001
1P0011E00C0000C001
100C01000000000001
111111111111111111
```

### Controles

| Tecla   | Ação |
|---------|--------|
| **W**   | Mover para cima |
| **A**   | Mover para a esquerda |
| **S**   | Mover para baixo  |
| **D**   | Mover para a direita  |
| **ESC** | Sair do programa |

---

# 🎮 Divirta-se e boa sorte com o mapa difícil!
