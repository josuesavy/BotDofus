FrontEnd :
AccountManager
 [ ] Faire une bonne GUI pour l'abonnement automatique des comptes
 [ ] Mettre une msgbox avec option remember pour expliquer comment importer des comptes (cf. https://stackoverflow.com/a/35132465)

Main
 [OK] L'energie max du bot s'affiche avec une incrémentation d'un +1 (O.o)
 [ ] Ajouter un timer qui update la life du bot quand il est en régénération

Character
 [OK] Make sure the reset characteristic button is enable when the bot has added characteristic and not the bonus of items or other (property: base)
 [OK] The current job of the character is not display in the list jobs

Inventory
 [OK] When we try equip item, in the list something change but not the good way, check this! For reproduce the problem, we need an item with quantity > 1 and try to change his position
 [OK] Display malus and bonus in the inventory

Carte
 [ ] Ya pas d'animation quand une entité se déplace sur la carte
 [ ] Donner une taille fixe à la carte lors du resize de la fenêtre du bot
 [OK] In fight, the map display the interactive elements (resources, door, etc.) while not

Flood
 [ ] Ajouter et supprimer une phrase dans la liste
 [ ] Le bouton pour lancer le flood n'a pas d'event

Options
 [ ] L'affichage de la planification est un peu moche
 [OK] Mettre une option permettant d'empêcher les déconnections pour inactivité

Divers
 [OK] La fenêtre est trop grande pour certaines résolutions graphique. Faire en sorte d'ajuster, permettre un certain resize sur certains widgets pour régler le problème
 [ ] Quand on arrête le script depuis le module, actualiser les actions dans la liste du management des scripts
 [ ] Mettre des tooltips un peu partout afin d'informer l'utilisateur


BackEnd :
AccountForm
 [ ] Faire la procédure de demande et d'envoi du code pour desactivé l'AnkShield (libcurl)

Network
 [OK] probleme de lecture du paquet, des fois l'id est pas bien détecté

ConnectionDialog
 [ ] Faire en sorte qu'on puisse voir l'avancer du chargement de chaque partie d'initialization du logiciel

AccountManager
 [ ] Faire toute la procédure de connexion/déconnexion, demande d'apikey pour abonner les comptes (cf. knowledge.txt) (libcurl)

Character
 [OK] When you request the entitylook attribute the proxy if there is one, full anonymat please

Inventaire
 [OK] Nouveau paquet a gérer SetUpdateMessage (useless, for the bot)
 [OK] Pour certains items de type différent (hat, ring, etc..) quand on l'equipe, c'est pas actualiser dans l'inventaire à car ya pas de paquet pour

Map
 [OK] Antibot sur la banque d'Astrub (191104002): des cellules marchable dans la banque vue de l'extérieur
 [OK] Des fois le bot reste en loop infinie quand on lui demande de bouger ou de changer de map (location: Pathfinding.cpp:124-135) 

Combat
 [ ] Revoir l'IA en combat, il semblerait qu'il a déjà la po pour attaquer mais il bouge avant alors qu'il peut le faire après
 [OK] Revoir toute les attributions des points de caractéristiques en combat car à cause de ça le bot ne fait plus rien et meure...
 [OK] Quand le bot lance un premier combat il close déjà le combat alors qu'on lui a pas demandé (auto à cause du mode restreint)
 [OK] Lorsque le perso perd de la vie en combat le maxlife et le lifepoint decendent en même temps
 [ ] Make some timers for the bot can throw spell (fuck antibot) 

Statistiques
 [ ] Rajouter le flood (Total messages, reussis, echoues)
 [ ] Rajouter l'inventaire (total ressources, combat, recolte, total objets, combat, recolte)
 [ ] Check remove the incrementation when you try to increase characteristic and you have an access denied

Divers
 [ ] Il y a une mesure anti-bot (ou pas) où j'arrive pas a récup toute les mapids des maps...
 [ ] Certaines cartes ont des voisins inconnue quand on veut se deplacer
 [OK] Lors de la connexion d'un groupe, vérifier si tous sont sur le même serveur (bof)
 [OK] Revoir le pathfinding, il semblerait qu'il soit cassé
 [ ] Vérifier si CheckFileRequestMessage fonctionne bien
 [OK] Quand on reconnecte le bot, il parle d'une histoire de régénération
 [ ] Des fois quand le bot se fait déco pour inactivité les logs sur la console sont pas mis à jour obligé de le reco pour avoir les dernière log sur la console
 [OK] Le bot plante sur certaines map genre quand on demande à D2OManagerSingleton pour une data (localisation: 3,-18:Astrub - Dans le paquet MapComplementaryInformationsDataMessage)
 [ ] Verifier sois même les fichiers du jeu à partir du cytrus.json: https://launcher.cdn.ankama.com/cytrus.json et télécharger à partir de: https://launcher.cdn.ankama.com/dofus/releases/main/windows/5.0_2.61.10.17.json ({game}/releases/{build}/{platform}/{version}.json) (libcurl)
 [ ] Au delà de 250 messages dans le LogMessage, certains message de fin sont perdu...

Infos
 Au lancement d'un compte, s'il y a trop de softwares en cours sur le pc ça plante et donne une erreur: "Could not load igc library.", ig9icd32!DumpRegistryKeyDefinitions, "C:\Windows\System32\DriverStore\FileRepository\iigd_dch.inf_amd64_3abed7b83f378c61\ig9icd32.dll"
 C'est un problème côté processeur, carte graphique