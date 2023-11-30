# Comment coder proprement ?

**Participer au projet, d'accord, mais faites le proprement !**

# Méthode SOLID

## Principes de responsabilité unique (SRP)

Le principe de responsabilité unique (SRP) est un principe de conception logicielle qui stipule qu'une classe doit avoir une seule raison de changer. En d'autres termes, une classe ne doit avoir qu'une seule responsabilité.

Dans le cas contraire, si une classe a plus d'une responsabilité, les responsabilités deviennent couplées. Les changements apportés à une responsabilité peuvent affecter les autres responsabilités, ce qui entraîne des effets secondaires et des bugs.

Cas de mauvaise pratique :

```cpp

class User {
public:
	User(string name, string email, string password) {
		this->name = name;
		this->email = email;
		this->password = password;
	}

	void save() {
		// Sauvegarde l'utilisateur dans la base de données
	}

	void sendEmail(string subject, string content) {
		// Envoie un email à l'utilisateur
	}

	void sendSMS(string content) {
		// Envoie un SMS à l'utilisateur
	}

private:
	string name;
	string email;
	string password;
};

```

Ici la classe User a 3 responsabilités :
- Sauvegarder l'utilisateur dans la base de données
- Envoyer un email à l'utilisateur
- Envoyer un SMS à l'utilisateur

Ces 3 responsabilités sont couplées, si on modifie la façon de sauvegarder l'utilisateur dans la base de données, on risque de modifier la façon d'envoyer un email ou un SMS à l'utilisateur.

Cas de bonne pratique :

```cpp	
class User {
public:
	User(string name, string email, string password) {
		this->name = name;
		this->email = email;
		this->password = password;
	}

	void save() {
		// Sauvegarde l'utilisateur dans la base de données
	}

private:
	string name;
	string email;
	string password;
};

__interface EmailSender {
public:
	void sendEmail(string subject, string content);
};

__interface SMSSender {
public:
	void sendSMS(string content);
};

class EmailSenderImpl : public EmailSender {
public:
	void sendEmail(string subject, string content) {
		// Envoie un email à l'utilisateur
	}
};

class SMSSenderImpl : public SMSSender {
public:
	void sendSMS(string content) {
		// Envoie un SMS à l'utilisateur
	}
};
```

Ici la classe User a une seule responsabilité : sauvegarder l'utilisateur dans la base de données.

Les responsabilités d'envoyer un email ou un SMS à l'utilisateur sont déléguées à d'autres classes.

## Principe ouvert/fermé (OCP)

Le principe ouvert/fermé (OCP) est un principe de conception logicielle qui stipule que les entités logicielles (classes, modules, fonctions, etc.) doivent être ouvertes pour l'extension, mais fermées pour la modification.

En d'autres termes, une classe doit être facilement extensible sans avoir à modifier son code source.

Cas de mauvaise pratique :

```cpp
// ouverture d'une porte à la main
class Door {
public:
	void open() {
		// ouvre la porte
	}

	void close() {
		// ferme la porte
	}

	bool isOpen() {
		// retourne true si la porte est ouverte, false sinon
	}
};

class Refregirator {
public:
	void open() {
		// ouvre le réfrigérateur
	}
		
	void close() {
		// ferme le réfrigérateur
	}

	bool isOpen() {
		// retourne true si le réfrigérateur est ouvert, false sinon
	}
};

class Drawer {
public:
	void open() {
		// ouvre le tiroir
	}

	void close() {
		// ferme le tiroir
	}

	bool isOpen() {
		// retourne true si le tiroir est ouvert, false sinon
	}
};

class Hand {
public:
	void openDoor(Door door) {
		door.open();
	}

	void closeDoor(Door door) {
		door.close();
	}

	void openRefregirator(Refregirator refregirator) {
		refregirator.open();
	}

	void closeRefregirator(Refregirator refregirator) {
		refregirator.close();
	}

	void openDrawer(Drawer drawer) {
		drawer.open();
	}

	void closeDrawer(Drawer drawer) {
		drawer.close();
	}

	bool isDoorOpen(Door door) {
		return door.isOpen();
	}

	bool isRefregiratorOpen(Refregirator refregirator) {
		return refregirator.isOpen();
	}

	bool isDrawerOpen(Drawer drawer) {
		return drawer.isOpen();
	}
};
```

Ici la classe Hand est ouverte pour l'extension, mais fermée pour la modification. Si on veut ouvrir une porte avec un pied, il faut modifier la classe Hand.
Cas de bonne pratique :

```cpp
__interface Executable{
	void open();
	void close();
	bool isOpen();
};

class Door : public Executable {
public:
	void open() {
		// ouvre la porte
	}

	void close() {
		// ferme la porte
	}

	bool isOpen() {
		// vérifie si la porte est ouverte
	}
};

class Refregirator : public Executable {
public:
	void open() {
		// ouvre le réfrigérateur
	}

	void close() {
		// ferme le réfrigérateur
	}

	bool isOpen() {
		// vérifie si le réfrigérateur est ouvert
	}
};

class Drawer : public Executable {
public:
	void open() {
		// ouvre le tiroir
	}

	void close() {
		// ferme le tiroir
	}

	bool isOpen() {
		// vérifie si le tiroir est ouvert
	}
};

class Hand {
public:
	void open(Executable executable) {
		executable.open();
	}

	void close(Executable executable) {
		executable.close();
	}

	bool isOpen(Executable executable) {
		return executable.isOpen();
	}
};
```

Ici la classe Hand est ouverte pour l'extension, mais fermée pour la modification. Si on veut ouvrir une porte avec un pied, il suffit de créer une classe Foot qui implémente l'interface Executable.

## Principe de substitution de Liskov (LSP)

Le principe de substitution de Liskov (LSP) est un principe de conception logicielle introduit par Barbara Liskov en 1987. Il est un principe de sous-typage qui définit les relations entre les sous-types et les types.

Si S est un sous-type de T, alors les objets de type T peuvent être remplacés par des objets de type S sans altérer les propriétés désirables du programme.

Ça veut dire que si une classe A hérite d'une classe B, alors on doit pouvoir utiliser un objet de type A partout où on utilise un objet de type B.

Cas de mauvaise pratique :

```cpp
class Rectangle {
protected:
	int width;
	int height;
public:
	void setWidth(int width) {
		this->width = width;
	}

	void setHeight(int height) {
		this->height = height;
	}

	int getWidth() {
		return width;
	}

	int getHeight() {
		return height;
	}

	int getArea() {
		return width * height;
	}
};

class Square : public Rectangle {
public:
	void setWidth(int width) {
		this->width = width;
		this->height = width;
	}

	void setHeight(int height) {
		this->width = height;
		this->height = height;
	}
};
```

Ici la classe Square hérite de la classe Rectangle, mais elle ne respecte pas le principe de substitution de Liskov. En effet, on ne peut pas utiliser un objet de type Square partout où on utilise un objet de type Rectangle.

Parce que si on utilise un objet de type Rectangle, on peut modifier sa largeur et sa hauteur indépendamment, mais si on utilise un objet de type Square, on ne peut pas modifier sa largeur et sa hauteur indépendamment, les deux types ne sont pas régis par les mêmes règles.

Cas de bonne pratique :

```cpp
__interface Shape {
	void setWidth(int width);
	void setHeight(int height);
	int getWidth();
	int getHeight();
	int getArea();
};

class Rectangle : public Shape {
protected:
	int width;
	int height;
public:
	void setWidth(int width) {
		this->width = width;
	}

	void setHeight(int height) {
		this->height = height;
	}

	int getWidth() {
		return width;
	}

	int getHeight() {
		return height;
	}

	int getArea() {
		return width * height;
	}
};

class Square : public Shape {
protected:
	int width;
public:
	void setWidth(int width) {
		this->width = width;
	}

	void setHeight(int height) {
		this->width = height;
	}

	int getWidth() {
		return width;
	}

	int getHeight() {
		return width;
	}

	int getArea() {
		return width * width;
	}
};
```

Ici la classe Square hérite de la classe Rectangle, et elle respecte le principe de substitution de Liskov. En effet, on peut utiliser un objet de type Square partout où on utilise un objet de type Rectangle.

Parce que si on utilise un objet de type Rectangle, on peut modifier sa largeur et sa hauteur indépendamment, et si on utilise un objet de type Square, on peut modifier sa largeur et sa hauteur indépendamment, les deux types sont régis par les mêmes règles.

## Principe de ségrégation des interfaces (ISP)

Le principe de ségrégation des interfaces (ISP) stipule qu'aucun client ne doit être forcé d'utiliser des méthodes dont il n'a pas besoin. En d'autres termes, les interfaces ne doivent pas être trop larges.

Les clients ne doivent pas être forcés de dépendre d'interfaces qu'ils n'utilisent pas.

Il faut donc découper les interfaces en plusieurs interfaces plus petites et plus spécifiques afin que les clients n'aient pas à implémenter des méthodes qui ne les intéressent pas.

Cas de mauvaise pratique :

```cpp
__interface Worker {
	void work();
	void eat();
};

class Human : public Worker {
public:
	void work() {
		// travaille
	}

	void eat() {
		// mange
	}
};

class Robot : public Worker {
public:
	void work() {
		// travaille
	}

	void eat() {
		// mange
	}
};
```

Ici la classe Human et la classe Robot implémentent l'interface Worker, mais elles ne respectent pas le principe de ségrégation des interfaces. En effet, la classe Human implémente la méthode eat() qui ne l'intéresse pas, et la classe Robot implémente la méthode eat() qui ne l'intéresse pas.

Cas de bonne pratique :

```cpp
__interface Worker {
	void work();
};

__interface Eater {
	void eat();
};

class Human : public Worker, public Eater {
public:
	void work() {
		// travaille
	}

	void eat() {
		// mange
	}
};

class Robot : public Worker {
public:
	void work() {
		// travaille
	}
};
```

Ici la classe Human et la classe Robot implémentent l'interface Worker, et elles respectent le principe de ségrégation des interfaces. En effet, la classe Human implémente la méthode eat() qui l'intéresse, et la classe Robot n'implémente pas la méthode eat() qui ne l'intéresse pas.

## Principe d'inversion de dépendance (DIP)

Le principe d'inversion de dépendance (DIP) stipule que les modules de haut niveau ne doivent pas dépendre des modules de bas niveau, les deux doivent dépendre d'abstractions.

Les abstractions ne doivent pas dépendre des détails, les détails doivent dépendre des abstractions.

Il faut donc découper les modules en plusieurs modules plus petits et plus spécifiques afin que les modules de haut niveau ne dépendent pas des modules de bas niveau.

Cas de mauvaise pratique :

```cpp
class MySQL {
public:
	void connect() {
		// connexion à MySQL
	}
};

class User {
private:
	MySQL mySQL;
public:
	void save() {
		mySQL.connect();
		// sauvegarde l'utilisateur
	}
};
```

Ici la classe User dépend de la classe MySQL, mais elle ne respecte pas le principe d'inversion de dépendance. En effet, la classe User dépend de la classe MySQL qui est un module de bas niveau.

Cas de bonne pratique :

```cpp
__interface Database {
	void connect();
};

class MySQL : public Database {
public:
	void connect() {
		// connexion à MySQL
	}
};

class User {
private:
	Database* database;
public:
	void save() {
		database.connect();
		// sauvegarde l'utilisateur
	}
};
```

Ici la classe User dépend de la classe Database, et elle respecte le principe d'inversion de dépendance. En effet, la classe User dépend de la classe Database qui est une abstraction.

# Méthode KISS

Le principe KISS (Keep It Simple, Stupid) stipule que la plupart des systèmes fonctionnent mieux s'ils sont maintenus simples plutôt que complexes.

Il faut donc éviter de complexifier le code, et il faut privilégier la simplicité.

Cas de mauvaise pratique :

```cpp
void displayHelloWorld() {
    std::cout << "Hello World!" << std::endl;
}

int main() {
	auto displayHelloWorld_l = []() {
		displayHelloWorld();
	};

	displayHelloWorld_l();
	
	return 0;
}
```

Ici le code est trop complexe et pourrait largement être simplifié.

Cas de bonne pratique :

```cpp
int main() {
	std::cout << "Hello World!" << std::endl;
	
	return 0;
}
```

Ici le code est simple et il n'y a pas besoin de le complexifier.

# Méthode DRY

Le principe DRY (Don't Repeat Yourself) stipule qu'il faut éviter de répéter le code et privilégier la réutilisation du code.

Cas de mauvaise pratique :

```cpp
class User {
private:
	std::string firstName;
	std::string lastName;
	std::string email;
	std::string password;

public:
	User(std::string firstName, std::string lastName, std::string email, std::string password) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->email = email;
		this->password = password;
	}

	std::string getFirstName() {
		return firstName;
	}

	std::string getLastName() {
		return lastName;
	}

	std::string getEmail() {
		return email;
	}

	std::string getPassword() {
		return password;
	}
};

class Admin {
private:
	std::string firstName;
	std::string lastName;
	std::string email;
	std::string password;
public:
	Admin(std::string firstName, std::string lastName, std::string email, std::string password) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->email = email;
		this->password = password;
	}

	std::string getFirstName() {
		return firstName;
	}

	std::string getLastName() {
		return lastName;
	}

	std::string getEmail() {
		return email;
	}

	std::string getPassword() {
		return password;
	}
};
```

Ici le code est répété et pourrait largement être réutilisé.

Cas de bonne pratique :

```cpp
class User {
private:
	std::string firstName;
	std::string lastName;
	std::string email;
	std::string password;
public:
	User(std::string firstName, std::string lastName, std::string email, std::string password) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->email = email;
		this->password = password;
	}

	std::string getFirstName() {
		return firstName;
	}

	std::string getLastName() {
		return lastName;
	}

	std::string getEmail() {
		return email;
	}

	std::string getPassword() {
		return password;
	}
};

class Admin : public User {
public:
	Admin(std::string firstName, std::string lastName, std::string email, std::string password) : User(firstName, lastName, email, password) {}
};
```

Ici le code est réutilisé et il n'y a pas besoin de le répéter.