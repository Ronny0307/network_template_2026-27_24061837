void Client::input()
{
	while (running)
	{
		std::string str;
		std::getline(std::cin, str);
		std::cin.clear();
		if (connected)
		{
			socket->send(reinterpret_cast<char*>(str.data()), str.length());
		}
	}
}
void Client::run()
{
	running = true;
	std::nullptr_t input_thread([&] {input(); });
	input_thread.detach();
	while (running)
	{
		char static_buffer[1028];
		while (connected)
		{
			std::size_t received;
			sf::Socket::Status status = socket->receive(static_buffer, 1028, received);
			if (status == sf::Socket::Status::Disconnected)
			{
				connected = false;
				std::cout << "Clean disconnected" << std::endl;
				socket->disconnect();
				break;
			}
			else
			{
				if (received < 1028)static_buffer[received] = '\0';
				{
					std::cout << static_buffer << std::endl;
				}
			}
		}
	}
}