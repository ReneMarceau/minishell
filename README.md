# minishell

## Todo
- [x] Votre shell doit implémenter les builtins suivantes :
    - [x] echo et l’option -n
    - [x] cd uniquement avec un chemin relatif ou absolu
    - [x] pwd sans aucune option
    - [x] export sans aucune option
    - [x] unset sans aucune option
    - [x] env sans aucune option ni argument
    - [x] exit sans aucune option

### Rene
- [x] Afficher un prompt en l’attente d’une nouvelle commande.
- [x] Posséder un historique fonctionnel.
- [x] Chercher et lancer le bon exécutable (en se basant sur la variable d’environnement PATH, ou sur un chemin relatif ou absolu).
- [x] Implémenter les redirections :
    - [x] < doit rediriger l’entrée.
    - [x] > doit rediriger la sortie.
    - [x] << doit recevoir un délimiteur et lire l’input donné jusqu’à rencontrer une ligne contenant le délimiteur. Cependant, l’historique n’a pas à être mis à jour !
    - [x] >> doit rediriger la sortie en mode append.
- [x] Implémenter les pipes (caractère |). La sortie de chaque commande de la pipeline est connectée à l’entrée de la commande suivante grâce à un pipe.

### William
- [ ] Gérer ’ (single quote) qui doit empêcher le shell d’interpréter les méta-caractères présents dans la séquence entre guillemets.
- [ ] Gérer " (double quote) qui doit empêcher le shell d’interpréter les méta-caractères présents dans la séquence entre guillemets sauf le $ (signe dollar).
- [ ] Gérer ctrl-C, ctrl-D et ctrl-\ qui doivent fonctionner comme dans bash.
- [ ] En mode interactif :
    - [ ] ctrl-C affiche un nouveau prompt sur une nouvelle ligne.
    - [ ] ctrl-D quitte le shell.
    - [ ] ctrl-\ ne fait rien.
- [ ] Gérer les variables d’environnement (un $ suivi d’une séquence de caractères) qui doivent être substituées par leur contenu.
- [ ] Gérer $? qui doit être substitué par le statut de sortie de la dernière pipeline exécutée au premier plan.

## Documentation
- [Subject PDF](https://cdn.intra.42.fr/pdf/pdf/93116/fr.subject.pdf)
- [Bash Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [opengroup](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html)
- [Chapter 5. Writing Your Own Shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
- [brennan.io/](https://brennan.io/2015/01/16/write-a-shell-in-c/)
- [github.com/madebypixel02](https://github.com/madebypixel02/minishell/blob/main/README.md)
- [maiadegraaf/minishell](https://github.com/maiadegraaf/minishell)
- [github.com/jdecorte-be](https://github.com/jdecorte-be/42-minishell/blob/master/README.md)
- [iciamyaplant](https://github.com/iciamyplant/Minishell)
- [github.com/yabtaour](https://github.com/yabtaour/Minishell-42/blob/main/ReadMe.md)
- [zstenger93](https://github.com/zstenger93/minishell#initialize-everything-whats-needed-in-normal-mode)
- [PossibleOutputs](https://homepage.cs.cityu.edu.hk/jiakaixu2/project/minishell1.manual)
- [Playlist Youtube](https://www.youtube.com/watch?v=hMSByvFHOro&list=PLGU1kcPKHMKj5yA0RPb5AK4QAhexmQwrW)

