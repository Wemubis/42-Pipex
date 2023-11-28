# Pipex

## Introduction

Ce projet a été réalisé dans le cadre du cursus à l'école 42. L'objectif est de comprendre et de manipuler les redirections et les pipelines en programmation système Unix, en implémentant un programme appelé "pipex" qui reproduit le fonctionnement de la commande shell "pipe".

<br>

## Description

Pipex simule le fonctionnement de la commande shell "pipe", qui permet de rediriger la sortie standard d'une commande vers l'entrée standard d'une autre. L'objectif est de créer un programme exécutable prenant en charge deux commandes passées en argument, et de rediriger la sortie de la première commande vers l'entrée de la deuxième à l'aide de pipes.

<br>

## Fonctionnalités

- Exécution de deux commandes en parallèle avec redirection de la sortie de la première vers l'entrée de la deuxième.
- Gestion de l'entrée et de la sortie à partir de fichiers ou des flux standard.
- Gestion des erreurs et affichage d'un message approprié.

<br>

## Implémentation

L'implémentation de pipex se divise en plusieurs étapes. Le programme doit créer un certain nombre de pipes, dupliquer les descripteurs de fichiers nécessaires, exécuter les commandes dans les processus fils, et gérer la redirection des flux entre les commandes.

<br>

## Utilisation

1. **Clonage du dépôt :**

    ```bash
    git clone https://github.com/Wemubis/pipex.git
    ```

2. **Compilation :**

    ```bash
    make
    ```

3. **Exécution :**

    ```bash
    ./pipex file1 "cmd1" "cmd2" file2
    ```

    Remplacez "file1", "cmd1", "cmd2", et "file2" par les noms de fichiers et les commandes appropriées.

<br>

## Exemple d'utilisation

```bash
./pipex infile "ls -l" "wc -l" outfile
