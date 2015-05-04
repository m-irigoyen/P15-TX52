# P15-TX52

Needed : SFML 2.0 (or higher) : http://www.sfml-dev.org/download/sfml/2.2/index-fr.php

Either do the standard CMake install, or configure your own project.

Standard CMake : follow the CMake-gui install. Choose ANOTHER directory for the build.
New project : SFML needs the window, system, graphics, and audio modules. Network not needed.



		EXPLICATIONS
	Modèle multi agent : On sépare les agents (logique décisionnelle) de leur corps / body (interactions physiques).
On modélise un environnement (ici la classe World). Cet environnement contient un certain nombre d'objets (classe abstraite PhysicalObject) qui ont une position dans le monde.
Les objets du monde n'ont AUCUNE LOGIQUE DECISIONNELLE. Ils peuvent entrer en collision avec d'autres agents, percevoir ce qui les entourent, etc, mais ne le font pas d'eux mêmes.

La logique décisionnelle est contenue dans un agent (classe Agent). Un agent est un cerveau, un controlleur, un marionnettiste. Il ne possède pas de présence physique à proprement parler dans le monde.
A cet effet, on le connecte à un Body. Le body n'a pas conscience de la connection.
L'agent va ensuite suivre un cycle de vie en 3 étapes (fonction live()) : 
- Perception : l'agent demande à son body ce qu'il perçoit. Le body va lui renvoyer ses perceptions, et toute information importante sur le body (par exemple, est ce que le body est blessé, a faim, ou soif).
- Réflexion : en fonction de ces informations, l'agent réfléchit à ce qu'il va faire, et prend une décision.
- Action : Ayant pris sa décision, l'agent l'applique en demandant au body d'effectuer la tâche correspondante.
On recommence ce cycle pour chaque agent à chaque frame (1 frame = 1 tour de boucle de la simulation (en général équivalent à une 1 image affichée à l'écran))

Normalement, les body interagissent avec l'environnement via des forces. Donc l'agent peut dire au body "bouge avec une force de temps dans cette direction.". Mais pas dans notre cas : nous on gère des ondes.
On part du principe que les ondes sont des objets à position fixe, dont le rayon augmente à chaque frame. Chaque onde possède également une longeur d'onde. L'environnement (classe World) se charge de faire bouger les ondes.
Les perceptions des body sont donc de la forme : "j'ai reçu telle onde, avec telle longueur d'onde"

Le simulateur regroupe toute la simulation. C'est lui qui se charge de créer le monde et les agents, de connecter les agents aux body, et puis de faire vivre tout ça dans sa fonction run.
A chaque frame ( = chaque appel à la fonction run() ), le simulateur va : 
- Faire vivre tous les agents.
- Faire vivre l'environnement.