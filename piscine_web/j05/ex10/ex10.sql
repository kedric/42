SELECT `titre` "Titre", `resum` "Resume", `annee_prod` FROM film INNER JOIN genre on film.id_genre = genre.id_genre WHERE genre.nom = 'erotic';
