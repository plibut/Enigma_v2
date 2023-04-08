#include <iostream>
#include <string>

std::string function_encrypt_message(std::string plaintext, std::string key)
// encrypt_message = function name | plaintext und key die variablen die es bekommt und mit den es rechnen wird
{
	std::string fully_encrypted_message;
	int loop1;
	for (loop1 = 0; loop1 < plaintext.length(); loop1 = loop1 + 1)
	{
		char Message_char = plaintext[loop1]; // [loop1] accsest den jeweiligen value den wir derzeitig in der operation haben (loop1 wird also eine zahl seien obv.)
		char Key_Char = key[loop1];
		char Encrypted_message_char = Message_char ^ Key_Char;
		// ^ = XOR macht irgendwass mit bits und bringt aus 2 nummern ne neue 
		fully_encrypted_message = fully_encrypted_message + Encrypted_message_char; // Fügt das verschlüsselte Zeichen in umgekehrter Reihenfolge zum verschlüsselten Nachrichtenstring hinzu (ja das brauch ich wirklich so ausführlich ums zu verstehen bruh)
	}
	return fully_encrypted_message;
}

std::string function_decrypt_message(std::string encrypted_message, std::string key)
{
	std::string decrypted_message;
	int loop2;
	for (loop2 = 0; loop2 < encrypted_message.length(); loop2 = loop2 + 1)
	{
		char encrypted_char = encrypted_message[loop2];
		char key_char = key[loop2];
		char decrypted_char = encrypted_char ^ key_char;
		decrypted_message = decrypted_message + decrypted_char;
	}
	return decrypted_message;
}


int main()
{
	std::string user_word_input;
	std::string user_key_input;

	double encrypt_or_decrypt;

	std::cout << "Please choose an option " << "\n";
	std::cout << "(1)Encrypt or (2)Decrypt: " << "\n";
	std::cin >> encrypt_or_decrypt;
	std::cin.ignore(); // damit wird davoriger user input ignoriert (wichtig)


	if (encrypt_or_decrypt == 1)
	{

		std::cout << "Message Encrypt has ben choosen please enter your message: " << "\n";
		std::getline(std::cin, user_word_input);
		std::cout << "Please enter key: " << "\n";
		std::getline(std::cin, user_key_input);
		std::string encrypted_message = function_encrypt_message(user_word_input, user_key_input);
		// encrypt_message = function that is called | user_input_1, user_key variables it will put into the function

		std::cout << "\n" << "Your encrypted message is:" << "\n" << encrypted_message << "\n";

		if (user_word_input.length() != user_key_input.length()) // .length() ist eine function von std:: wirt zur auslesung der länge des strings benutzt.
		{
			std::cout << "Error: The key must be the same length as the message." << "\n";
			return 1;
		}
	}

	else if (encrypt_or_decrypt == 2)
	{
		std::string encrypted_message;
		std::cout << "Message Decrypt has ben choosen please enter your Encrypted message: " << "\n";
		std::getline(std::cin, encrypted_message);
		std::cout << "Please enter key: " << "\n";
		std::getline(std::cin, user_key_input);

		std::string decryption_done = function_decrypt_message(encrypted_message, user_key_input);

		std::cout << "\n" << "Your Encrypted message is: " << "\n" << decryption_done << "\n";
	}

	else
	{
		std::cout << "Please enter vailed input!";
	}
	// v3
	return 0;
}