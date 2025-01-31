
 # 🧩 Puzzle Game

![Version](https://img.shields.io/badge/version-1.0.0-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Language](https://img.shields.io/badge/language-C-orange.svg)

Un jeu de puzzle sophistiqué développé en C, avec une architecture modulaire et une gestion avancée des composants.

## 📁 Structure du Projet

```
puzzle-game/
├── .res                    # Ressources du jeu
├── .gitattributes         # Configuration Git
├── README.md              # Documentation
├── alltype.h              # Définitions des types communs
├── comp.c/h               # Gestion des composants
├── engine.c/h            # Moteur de jeu principal
├── event.c/h             # Gestion des événements
├── game.c/h              # Logique principale du jeu
├── map.c/h               # Gestion des niveaux
├── memory.c/h            # Gestion de la mémoire
├── menu.c/h              # Interface des menus
├── readme.txt            # Instructions supplémentaires
├── save.c/h              # Système de sauvegarde
├── shop.c/h              # Système de boutique
├── special_call.c/h      # Fonctions spéciales
├── timer.h               # Gestion du temps
└── window.c/h            # Gestion de l'interface graphique
```

## 🚀 Caractéristiques

- ⚙️ Moteur de jeu modulaire
- 🎮 Interface utilisateur optimisée
- 💾 Système de sauvegarde
- 🛒 Boutique in-game
- ⏱️ Gestion du temps
- 🗺️ Système de niveaux
- 🎨 Composants graphiques personnalisables

## 🛠️ Installation

### Prérequis
- Compilateur C (GCC recommandé)
- Make
- Bibliothèques système standard

### Compilation
```bash
# Compiler le projet
make all

# Compiler en mode debug
make debug

# Nettoyer les fichiers de compilation
make clean
```

## 🎮 Modules Principaux

### Engine (engine.c/h)
- Moteur principal du jeu
- Gestion des boucles de jeu
- Synchronisation des composants

### Event (event.c/h)
- Gestion des entrées utilisateur
- Système d'événements
- Callbacks et hooks

### Game (game.c/h)
- Logique du jeu
- États de jeu
- Règles et méchaniques

### Map (map.c/h)
- Chargement des niveaux
- Gestion des obstacles
- Génération de puzzle

### Memory (memory.c/h)
- Allocation mémoire optimisée
- Gestion des ressources
- Nettoyage mémoire

### Menu (menu.c/h)
- Interface des menus
- Navigation
- Options de jeu

### Window (window.c/h)
- Gestion de l'affichage
- Rendu graphique
- Gestion des fenêtres

## 🎯 Comment Jouer

1. **Contrôles**
   - Flèches directionnelles : Déplacement
   - ESPACE : Sélection
   - ESC : Menu
   - R : Recommencer niveau

2. **Objectifs**
   - Résoudre les puzzles
   - Débloquer de nouveaux niveaux
   - Collecter des points
   - Améliorer votre score

## 💾 Système de Sauvegarde

Le système de sauvegarde (save.c/h) permet de :
- Sauvegarder la progression
- Conserver les meilleurs scores
- Garder les préférences utilisateur
- Restaurer l'état du jeu

## 🛍️ Système de Boutique

La boutique (shop.c/h) offre :
- Achat de niveaux bonus
- Déblocage de thèmes
- Objets spéciaux
- Bonus de jeu

## 🔧 Configuration

Les paramètres peuvent être modifiés dans :
- alltype.h pour les constantes globales
- config.h pour les paramètres de jeu
- window.h pour les paramètres d'affichage

## 🐛 Débogage

Pour le mode debug :
1. Compiler avec `make debug`
2. Utiliser les logs dans la console
3. Vérifier memory.c pour les fuites mémoire

## 👥 Contribution

1. Fork le projet
2. Créer une branche (`git checkout -b feature/nouvelle-fonctionnalite`)
3. Commit (`git commit -am 'Ajout nouvelle fonctionnalité'`)
4. Push (`git push origin feature/nouvelle-fonctionnalite`)
5. Créer une Pull Request

## 📝 License

Ce projet est sous licence MIT. Voir le fichier LICENSE pour plus de détails.

---
⭐ N'hésitez pas à donner une étoile si vous appréciez ce projet ! ⭐
