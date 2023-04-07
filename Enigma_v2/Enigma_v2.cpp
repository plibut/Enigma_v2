#include <iostream>
#include <string>

int main() {
	std::string user_input_1; // user_input_1 = user message that will be encrypted
	std::string user_key; // key that will be enterd by user

	std::cout << "Enter the message: ";
	std::getline(std::cin, user_input_1); // std::getline setzt eine komplette text linie in die string variable
	std::cout << "Enter the key: ";
	std::getline(std::cin, user_key);


	if (user_input_1.length() != user_key.length()) // .length() ist eine function von std:: wirt zur auslesung der länge des strings benutzt.
	{
		std::cout << "Error: The key must be the same length as the message." << "\n";
		return 1;
	}

	std::string Fully_encrypted_message;
	int loop1;

	for (loop1 = 0; loop1 < user_input_1.length(); loop1 = loop1 + 1)
	{
		char Message_char = user_input_1[loop1]; // [loop1] accsest den jeweiligen value den wir derzeitig in der operation haben (loop1 wird also eine zahl seien obv.)
		char Key_Char = user_key[loop1];
		char Encrypted_message_char = Message_char ^ Key_Char;
		// ^ = XOR macht irgendwass mit bits und bringt aus 2 nummern ne neue 
		Fully_encrypted_message = Encrypted_message_char + Fully_encrypted_message; // Fügt das verschlüsselte Zeichen in umgekehrter Reihenfolge zum verschlüsselten Nachrichtenstring hinzu (ja das brauch ich wirklich so ausführlich ums zu verstehen bruh)
	}

	std::cout << "Encrypted message: " << Fully_encrypted_message << "\n";

	return 0;

}