// Define a Product struct with: id, name, price
// Write 3 products to a binary file
// Read all products and display them
// UPdate the price of product with id = 2

#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

// Initialize a Product struct with id, name and price
struct Product {
	int id = 0;
	char name[151];
	double price;
};

// There are 3 operation the user can choose
// - Add new products
// - List the available products
// - Adjust the available products


// To add the new product, the user must specify ID, name and price
void AddProducts(Product productinfo, int& productquantities, int& previousid) {
	// Write the product to a binary file
	ofstream output("products.bin", ios::binary);
	if (!output.is_open()) {
		cout << "Error: Cannot open file" << endl;
	}

	// Specify the number of new products
	cout << "Number of new products: "; cin >> productquantities;

	// Let the user input new products until the end of the loop
	for (int i = 0; i < productquantities; i++) {
		cout << "---Product " << previousid << "---" << endl;

		cout << "Enter the ID " << "(Previous ID: " << previousid - 1 << "): "; cin >> productinfo.id; // Input the number order
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Handle the buffer
		previousid = productinfo.id; // Save the ID to let the user know what is the previous ID

		cout << "Product name: "; cin.getline(productinfo.name, 151); // Input the product name

		cout << "Product price: "; cin >> productinfo.price; // Input the product price
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Handle the buffer

		output.write(reinterpret_cast<char*>(&productinfo), sizeof(Product)); // Write the information in the struct to the binary file

		cout << endl;
	}

	output.close();

}

void ListingProducts(Product productinfo) {
	ifstream input("products.bin", ios::binary);
	if (!input.is_open()) {
		cout << "Error: Cannot open file" << endl;
	}

	input.seekg(0, ios::beg); // Reset the pointer to the beginning of the file

	cout << endl;

	while (input.read(reinterpret_cast<char*>(&productinfo), sizeof(Product)) /* Read the information and assign to the struct */) {
		// Print out information
		cout << "--- Product " << productinfo.id << " ---" << endl;
		cout << "ID: " << productinfo.id << endl;
		cout << "Product type: " << productinfo.name << endl;
		cout << "Product price: " << productinfo.price << endl;

		cout << endl;
	}

	input.close();
}

void AdjustingProducts(Product& productinfo) {
	fstream file("products.bin", ios::binary | ios::in | ios::out);
	if (!file.is_open()) {
		cout << "Error: Cannot open file" << endl;
	}

	int findid;
	cout << "Type the ID: "; cin >> findid; // Ask the user to specify the ID that he/she wants to access
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	bool found = false;
	while (file.read(reinterpret_cast<char*>(&productinfo), sizeof(Product))) {
		if (productinfo.id == findid) { // If found the id, let the user adjusts the name or the price
										// If the user doesn't want to change the name or price, he/she can type the name/price again
			found = true;
			cout << "Type a new product type (Previous type: " << productinfo.name << "): "; cin.getline(productinfo.name, 151);
			cout << "Type a new price (Previous price: " << productinfo.price << "): "; cin >> productinfo.price;

			file.seekg((findid - 1) * sizeof(Product), ios::beg); // Get back the start of the file to write the whole struct again
			file.write(reinterpret_cast<char*>(&productinfo), sizeof(Product));
			return;
		}
	}

	// If not found, let the user know
	if (!found) cout << "ID not found" << endl;

	file.close();
}

int main() {
	// Let the user choose the operations
	int query = 0;
	cout << "Type the number to operate tasks: " << endl;
	cout << "1. Add products\n" << "2. Listing available products\n" << "3. Adjusting available products\n";
	cin >> query;

	Product productinfo;
	int productquantities = 0, previousid = 1;

	if (query == 1) {
		AddProducts(productinfo, productquantities, previousid);
	}
	else if (query == 2) {
		ListingProducts(productinfo);
	}
	else if (query == 3) {
		AdjustingProducts(productinfo);
	}

	return 0;
}