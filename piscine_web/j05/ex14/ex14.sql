SELECT `etage_salle` "etage", SUM(nbr_siege) AS SIEGE FROM salle GROUP BY etage_salle ORDER BY SIEGE DESC;
