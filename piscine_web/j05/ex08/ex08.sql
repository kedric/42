SELECT `nom`, `prenom`, date(`date_naissance`) "date_naissance" FROM `fiche_personne` WHERE year(`date_naissance`) = 1989 ORDER BY `nom` ASC;
