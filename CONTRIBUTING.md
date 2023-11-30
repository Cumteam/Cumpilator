# Comment coder proprement ?

**Participer au projet, d'accord, mais faites le proprement !**

# M�thode SOLID

## Principes de responsabilit� unique (SRP)

Le principe de responsabilit� unique (SRP) est un principe de conception logicielle qui stipule qu'une classe doit avoir une seule raison de changer. En d'autres termes, une classe ne doit avoir qu'une seule responsabilit�.

Dans le cas contraire, si une classe a plus d'une responsabilit�, les responsabilit�s deviennent coupl�es. Les changements apport�s � une responsabilit� peuvent affecter les autres responsabilit�s, ce qui entra�ne des effets secondaires et des bugs.

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
		// Sauvegarde l'utilisateur dans la base de donn�es
	}

	void sendEmail(string subject, string content) {
		// Envoie un email � l'utilisateur
	}

	void sendSMS(string content) {
		// Envoie un SMS � l'utilisateur
	}

private:
	string name;
	string email;
	string password;
};

```

Ici la classe User a 3 responsabilit�s :
- Sauvegarder l'utilisateur dans la base de donn�es
- Envoyer un email � l'utilisateur
- Envoyer un SMS � l'utilisateur

Ces 3 responsabilit�s sont coupl�es, si on modifie la fa�on de sauvegarder l'utilisateur dans la base de donn�es, on risque de modifier la fa�on d'envoyer un email ou un SMS � l'utilisateur.

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
		// Sauvegarde l'utilisateur dans la base de donn�es
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
		// Envoie un email � l'utilisateur
	}
};

class SMSSenderImpl : public SMSSender {
public:
	void sendSMS(string content) {
		// Envoie un SMS � l'utilisateur
	}
};
```

Ici la classe User a une seule responsabilit� : sauvegarder l'utilisateur dans la base de donn�es.

Les responsabilit�s d'envoyer un email ou un SMS � l'utilisateur sont d�l�gu�es � d'autres classes.

## Principe ouvert/ferm� (OCP)

Le principe ouvert/ferm� (OCP) est un principe de conception logicielle qui stipule que les entit�s logicielles (classes, modules, fonctions, etc.) doivent �tre ouvertes pour l'extension, mais ferm�es pour la modification.

En d'autres termes, une classe doit �tre facilement extensible sans avoir � modifier son code source.

Cas de mauvaise pratique :

```cpp
// ouverture d'une porte � la main
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
		// ouvre le r�frig�rateur
	}
		
	void close() {
		// ferme le r�frig�rateur
	}

	bool isOpen() {
		// retourne true si le r�frig�rateur est ouvert, false sinon
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

Ici la classe Hand est ouverte pour l'extension, mais ferm�e pour la modification. Si on veut ouvrir une porte avec un pied, il faut modifier la classe Hand.
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
		// v�rifie si la porte est ouverte
	}
};

class Refregirator : public Executable {
public:
	void open() {
		// ouvre le r�frig�rateur
	}

	void close() {
		// ferme le r�frig�rateur
	}

	bool isOpen() {
		// v�rifie si le r�frig�rateur est ouvert
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
		// v�rifie si le tiroir est ouvert
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

Ici la classe Hand est ouverte pour l'extension, mais ferm�e pour la modification. Si on veut ouvrir une porte avec un pied, il suffit de cr�er une classe Foot qui impl�mente l'interface Executable.

## Principe de substitution de Liskov (LSP)

Le principe de substitution de Liskov (LSP) est un principe de conception logicielle introduit par Barbara Liskov en 1987. Il est un principe de sous-typage qui d�finit les relations entre les sous-types et les types.

Si S est un sous-type de T, alors les objets de type T peuvent �tre remplac�s par des objets de type S sans alt�rer les propri�t�s d�sirables du programme.

�a veut dire que si une classe A h�rite d'une classe B, alors on doit pouvoir utiliser un objet de type A partout o� on utilise un objet de type B.

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

Ici la classe Square h�rite de la classe Rectangle, mais elle ne respecte pas le principe de substitution de Liskov. En effet, on ne peut pas utiliser un objet de type Square partout o� on utilise un objet de type Rectangle.

Parce que si on utilise un objet de type Rectangle, on peut modifier sa largeur et sa hauteur ind�pendamment, mais si on utilise un objet de type Square, on ne peut pas modifier sa largeur et sa hauteur ind�pendamment, les deux types ne sont pas r�gis par les m�mes r�gles.

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

Ici la classe Square h�rite de la classe Rectangle, et elle respecte le principe de substitution de Liskov. En effet, on peut utiliser un objet de type Square partout o� on utilise un objet de type Rectangle.

Parce que si on utilise un objet de type Rectangle, on peut modifier sa largeur et sa hauteur ind�pendamment, et si on utilise un objet de type Square, on peut modifier sa largeur et sa hauteur ind�pendamment, les deux types sont r�gis par les m�mes r�gles.

## Principe de s�gr�gation des interfaces (ISP)

Le principe de s�gr�gation des interfaces (ISP) stipule qu'aucun client ne doit �tre forc� d'utiliser des m�thodes dont il n'a pas besoin. En d'autres termes, les interfaces ne doivent pas �tre trop larges.

Les clients ne doivent pas �tre forc�s de d�pendre d'interfaces qu'ils n'utilisent pas.

Il faut donc d�couper les interfaces en plusieurs interfaces plus petites et plus sp�cifiques afin que les clients n'aient pas � impl�menter des m�thodes qui ne les int�ressent pas.

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

Ici la classe Human et la classe Robot impl�mentent l'interface Worker, mais elles ne respectent pas le principe de s�gr�gation des interfaces. En effet, la classe Human impl�mente la m�thode eat() qui ne l'int�resse pas, et la classe Robot impl�mente la m�thode eat() qui ne l'int�resse pas.

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

Ici la classe Human et la classe Robot impl�mentent l'interface Worker, et elles respectent le principe de s�gr�gation des interfaces. En effet, la classe Human impl�mente la m�thode eat() qui l'int�resse, et la classe Robot n'impl�mente pas la m�thode eat() qui ne l'int�resse pas.

## Principe d'inversion de d�pendance (DIP)

Le principe d'inversion de d�pendance (DIP) stipule que les modules de haut niveau ne doivent pas d�pendre des modules de bas niveau, les deux doivent d�pendre d'abstractions.

Les abstractions ne doivent pas d�pendre des d�tails, les d�tails doivent d�pendre des abstractions.

Il faut donc d�couper les modules en plusieurs modules plus petits et plus sp�cifiques afin que les modules de haut niveau ne d�pendent pas des modules de bas niveau.

Cas de mauvaise pratique :

```cpp
class MySQL {
public:
	void connect() {
		// connexion � MySQL
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

Ici la classe User d�pend de la classe MySQL, mais elle ne respecte pas le principe d'inversion de d�pendance. En effet, la classe User d�pend de la classe MySQL qui est un module de bas niveau.

Cas de bonne pratique :

```cpp
__interface Database {
	void connect();
};

class MySQL : public Database {
public:
	void connect() {
		// connexion � MySQL
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

Ici la classe User d�pend de la classe Database, et elle respecte le principe d'inversion de d�pendance. En effet, la classe User d�pend de la classe Database qui est une abstraction.

# M�thode KISS

Le principe KISS (Keep It Simple, Stupid) stipule que la plupart des syst�mes fonctionnent mieux s'ils sont maintenus simples plut�t que complexes.

Il faut donc �viter de complexifier le code, et il faut privil�gier la simplicit�.

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

Ici le code est trop complexe et pourrait largement �tre simplifi�.

Cas de bonne pratique :

```cpp
int main() {
	std::cout << "Hello World!" << std::endl;
	
	return 0;
}
```

Ici le code est simple et il n'y a pas besoin de le complexifier.

# M�thode DRY

Le principe DRY (Don't Repeat Yourself) stipule qu'il faut �viter de r�p�ter le code et privil�gier la r�utilisation du code.

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

Ici le code est r�p�t� et pourrait largement �tre r�utilis�.

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

Ici le code est r�utilis� et il n'y a pas besoin de le r�p�ter.