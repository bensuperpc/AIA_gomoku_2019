# Gomoku

Gomoku est un jeu de tour par tour.

## Compilation

### Pour une compilation simple
Vous pouvez faire cette commande pour compiler le projet :

```bash
make -j 8
```
### Pour une re-compilation
Vous pouvez faire cette commande pour compiler le projet :

```bash
make re -j 8
```

### Pour nettoyer les fichiers
```bash
make fclean
```

### Pour le debug
GDB doit etre installé !
```bash
make gdb
```
### Avec valgrind
valgrind doit etre installé !
```bash
make valgrind
```

### Pour une compilation pour les units_tests

#### units_tests uniquement
```bash
make fclean
make tests_run -j 8
```

#### units_tests avec gcovr et sortie dans un fichier html
```bash
make fclean
make coverage_html_run -j 8
```

#### units_tests avec gcovr pour le coverage uniquement
```bash
make fclean
make coverage_run -j 8
```

#### units_tests avec gcovr pour les branch uniquement
```bash
make fclean
make branches_run -j 8
```

## Utilisation
Une fois le programme lancé, il faut démarrer la partie en générant la board avec cette commande :
```bash
START 20
```

En suite, vous pouvez jouer avec "TURN posX,posY".
```bash
TURN 1,1
```

L'IA jouera apres la commande, par ex :
```bash
5,5
```

Vous pouvez afficher la board en cours avec cette commande :
```bash
DISPLAY
```

## Programmation
```c++
#include "gomoku.hpp"

int main()
{
    //Create class
    gomoku gomoku_class;
    // Launch game
    return gomoku_class.game();
}
```

## Contribution
Les contributions ne sont pas encore ouvertent, tant que la review n'est pas passée :P

## Trello

## License
[MIT](https://choosealicense.com/licenses/mit/) 
