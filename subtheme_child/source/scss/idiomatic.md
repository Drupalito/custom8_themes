
# Conventions développement CSS

Ce document doit permettre d'uniformiser le code HTML/CSS à l'aide de différentes conventions.

Le but est de disposer d'un code maintenable facile à mettre en place sur l'ensembles des projets et que n'importe quel projet soit accessible à n'importe quel intervenant connaissant nos conventions.

## Table des matières

1. [Principes généraux](#general-principles)
1. [Indentation](#whitespace)
1. [Commentaires](#comments)
1. [Format](#format)
1. [Nommage](#naming)
1. [Organisation](#organization)
1. [Sources et inspiration](#thanks)

## 1. Principes généraux

* Tout code présent dans n'importe quelle base de code doit avoir l'air, d'avoir été écrit par une seule personne. Peu importe le nombre de personne qui ont contribué ;
* **Appliquer les conventions de manière stricte ;**

## 2. Indentation

* **Ne jamais mélanger espaces** et tabulations (configurer son éditeur) ;
* Privilégier les espaces, de préférence : **2 espaces en CSS** ;

Le fichier `.editorconfig` contient les options requises. Plus d'informations sur [editorconfig.org](http://editorconfig.org).

Astuce : Configurez votre éditeur afin qu'il affiche les "caractères invisibles". Cela vous permettra de supprimer les espaces en fin de ligne, les espaces dans les lignes vides et **évitera de polluer vos commits**.

## 3. Commentaires

Bien commenter son code est très important.

Prendre le temps de décrire les composants, comment ils fonctionnent, leurs limites, et la manière dont ils sont conçus. **Ne laissez pas les autres membres de l'équipe deviner le but d'un code inhabituel ou non trivial.**

La façon de commenter doit être simple et similaire dans toute base de code.

* Placer les commentaires sur une nouvelle ligne au-dessus de leur sujet ;
* Éviter les commentaires en fin de ligne ;
* Garder une longueur de ligne de taille raisonnable, par exemple 80 caractères ;
* Utiliser les commentaires comme bon vous semble pour diviser le code CSS en parties distinctes ;
* Rédiger les commentaires avec des majuscules et des minuscules et gardez une indentation constante pour le texte.

Ne pas oublier qu'une documentation va être automatiquement générée.

Astuce: Paramétrer votre éditeur à l'aide du plugin [Emmet](http://docs.emmet.io/) pour qu'il fournisse des raccourcis claviers qui produisent des commentaires conventionnels.

## 4. Format

Le format de code choisi doit assurer :

* Une bonne lisibilité ;
* Des commentaires clairs ;
* Une réduction des probabilités d'insertion accidentelle d'erreurs ;
* La production de fichiers diff et de résolution des problèmes pratiques.

### Conventions CSS

* **Indentation : 2 espaces** ;
* Validation W3C CSS (ou justifier la non conformité) ;
* Le nom des class CSS doit être en anglais ;
* Nommage `.class-name {}` ;
* Prohiber `!important` ;
* Limiter l'imbrication des sélecteurs (max. 2) ;
* Ajouter un espace après les deux points d'une déclaration ;
* Ajouter toujours un point-virgule à la fin de la dernière déclaration d’un bloc ;
* Écrire les règles sur une ligne lorsqu'elles contiennent une seule propriété ;
* Utiliser des minuscules pour les valeurs hexadécimales, exemple : #aaa ;
* Sauter une ligne entre chaque règle ;
* Prohiber l'utilisation d'ID pour styliser un bloc.
* Utiliser le même type de guillemets. *Doubles guillemets*, exemple : `content: ""` soit : `input[type="checkbox"]` ;
* Interdire de spécifier les unités pour les valeurs nulles, exemple : `margin: 0`.

```
.selector {
  // Styles du bloc actuel
  property: value;
  property2: value;

  p { // Descendent direct
    property:value;  // Bad
    property: value; // Good
  }

  .className {}  // Bad
  .CLASSNAME {}  // Bad
  .class_name {} // Bad
  .class-name{}  // Bad
  .class-name {} // Good
  .class__name {} // Good

  // Sélécteurs successifs (une par ligne)
  .selector-1, .selector-2, .selector-3 {} // Bad
  .selector-1,
  .selector-2,
  .selector-3 {} // Good

  // One liners
  .one-liner { margin: 0; border-radius: 5px; font-size: 15px; } // Bad
  .one-liner { margin: 0; } // Good: une propriété

  // Modifier des styles de base
  &--modifier {
    p { // Descendant de remplacement

    }
  }

  .indentation-tricks {
    // Aligner les variables pour assurer une bonne lisibilité
    // Voir SublimeText2 Plugin Alignment
    $var-alpha:   15px !default;
    $var-epsylon: true;
    $var-zeta:    false;
  }

  @media (min-width: 680px) {
    // Modifications pour le breakpoint
    // Avec Sass, on peut imbriquer `media
  }

  // Conditions
  @if $compact {
    // Case 1
  }
  @else {
    // Case 2
  }
}

// Ajouter une ligne blanche à la fin du fichier
```

Les longues valeurs de propriétés, séparées par des virgules *comme des ensembles de dégradés et d'ombres* peuvent être agencées sur plusieurs lignes de manière à améliorer la lisibilité et produire des fichiers diff plus utiles. Divers formats peuvent alors être utilisés comme le montre l'exemple donné ci-dessous :

```css
.selecteur {
  box-shadow:
    1px 1px 1px #000,
    2px 2px 1px 1px #ccc inset;
  background-image:
    linear-gradient(#fff, #ccc),
    linear-gradient(#f3c, #4ec);
}
```

### Préprocesseurs Sass Compass

* Placer toujours les déclarations `@extend` en début de bloc.
* Si possible, regrouper toutes les déclarations `include` en début de bloc juste après les déclarations `@extend`.

```
.selecteur-1 {
  @extend .other-rule;
  box-sizing: border-box;
  width: x-grid-unit(1);
  // Autres déclarations
}
```

## 5. Nommage

Utiliser des noms clairs et réfléchis pour les classes HTML.
Choisir un modèle de nommage cohérent et compréhensif qui a du sens à la fois dans les fichiers HTML et dans les fichiers CSS.

* **Le nom des classes doit être en anglais ;**
* Plusieurs mots dans une classe doivent être séparés par un trait d'union ;
* Utiliser des classes et non des IDs dans la mesure du possible.

Les déclarations utilisent les méthodologies OOCSS, SMACSS, BEM.

Par exemple, pour créer un `block header` contenant un logo :

```css
.header.logo   /* Bad */
.header-logo   /* Bad */
.header--logo  /* Good (modifier) */
.header__logo  /* Bad (elements) */
/* exception avec l'utilisation des helpers */
.header.mbn    /* Good (`.mbn` = helper donc autorisé) */
```

## 6. Organisation

L'organisation du code est une partie importante de n'importe quelle base de code CSS et devient cruciale pour les grosses bases de code.

* Utiliser des fichiers distincts (concaténés au cours de l'étape de compilation) pour aider à découper le code en différents composants ;
* Séparer de manière logique les différentes parties de code (à l'aide des commentaires) ;
* Utiliser des fichiers distincts (concaténés au cours de l'étape de compilation) pour aider à découper le code en différents composants ;
* Si un préprocesseur est disponible sur votre projet, stocker le code récurrent dans des variables pour la couleur, la typographie, les espacements, etc. ;
* Organiser les classes en suivant les méthodes OOCSS, SMACSS, BEM.

```
// Organisation des fichiers Scss
scss/
├── screen.scss
├── print.scss
├── base
│   ├── _colorz.scss
│   ├── _fonts.scss
│   ├── _from.scss
│   ├── _helpers.scss
│   ├── _reset.scss
│   ├── _spacing.scss
│   └── _typo.scss
├── components
│   ├── _breadcrumb.scss
│   ├── _button.scss
│   ├── _comments.scss
│   ├── _icon.scss
│   ├── _message.scss
│   ├── _pagination.scss
│   └── …
├── helpers
│   ├── _debug.scss
│   ├── _functions.scss
│   ├── _mixins.scss
│   └── _vars.scss
├── pages
│   ├── homepage.scss
│   ├── issues.scss
│   ├── profile.scss
│   └── …
└── vendors
    ├── jquery.prettyphoto.css
    ├── jquery.ui.css
    └── …
```

* Le dossier `/base` regroupe les fichiers contient les fichiers CSS de bases ;
* Le dossier `/components` contient les composants CSS ;
* Le dossier `/modules` contient les CSS des modules  ;
* Le dossier `/pages` contient les styles spécifiques pour les  pages.

> **En cas d'un multi-sites, un dossier `/share` peut être créé pour partager les styles entre différents sites.**

Fichiers contenus dans le dossier `/base`.

* `_fonts.scss` contient les appels vers les fonts exotiques ;
* `_reset.scss` uniformisation des styles à travers les navigateurs (basé sur normalize.css) ;
* `_helper.scss` contient une liste de sélecteurs à usage unique pouvant être étendu (typo, alignement, etc.) ;
* `_from.scss` contient les éléments de formulaire ;
* `_spacing.scss` contient les espacements, liste de sélecteurs à usage unique pouvant être étendu ;

## 7. Sources et inspiration

* [idiomatic.css](https://github.com/rwldrn/idiomatic.css)
* [idiomatic.html](https://github.com/rwldrn/idiomatic.html)
* [idiomatic.js](https://github.com/rwldrn/idiomatic.js)
