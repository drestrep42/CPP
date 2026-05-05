#include "Serializer.hpp"

int main()
{
	Data data;
	data.value = 42;

	std::cout << "Original data value: " << data.value << std::endl;

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized data (uintptr_t): " << serialized << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized data value: " << deserialized->value << std::endl;

	return 0;
}
