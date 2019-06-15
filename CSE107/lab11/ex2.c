#include <stdio.h>
#include <stdlib.h>

struct Book {
	char *name;
	char *author;
	int ISBN;
	int publishYear;
	int pageNumbers;
};

void printBook(struct Book *bookPtr) {
	printf("Name:%s Author:%s ISBN:%d publishYear:%d pageNumbers:%d\n", 
		bookPtr->name, bookPtr->author, bookPtr->ISBN, bookPtr->publishYear, bookPtr->pageNumbers);
}

void getAuthor(struct Book *books, char* author, int size) {
	printf("Books of author %s\n", author);
	for(int i = 0; i < size; i++) {
		if(books[i].author == author) {
			printBook(&books[i]);
		}
	}
	printf("\n");
}

int getEarliest(struct Book *books, int size) {

	int min = books[0].publishYear;
	int index = 0;

	for(int i = 0; i < size; i++) {
		if(books[i].publishYear < min) {
			min = books[i].publishYear;
			index = i;
		}
	}

	return index;

}

struct Book createBook(char *name, char *author, int ISBN, int publishYear, int pageNumbers) {

	struct Book book;
	struct Book *bookPtr = &book;

	bookPtr->name = name;
	bookPtr->author = author;
	bookPtr->ISBN = ISBN;
	bookPtr->publishYear = publishYear;
	bookPtr->pageNumbers = pageNumbers;

	return book;

}

int totalPage(struct Book *books, int size) {
	int pages = 0;
	for(int i = 0; i < size; i++) {
		pages += books[i].pageNumbers;
	}
	return pages;
}

int main() {

	int numOfBooks = 0;
	struct Book *books = malloc(20 * sizeof(struct Book));

	int i = 0;
	books[i] = createBook("A","A",1,5,1);
	i++;
	books[i] = createBook("A","B",2,6,1);
	i++;
	books[i] = createBook("A","A",3,3,1);
	i++;
	books[i] = createBook("A","D",4,4,3);
	i++;
	numOfBooks += 4;

	getAuthor(books, "A", numOfBooks);
	
	printf("Earliest: ");
	printBook(&books[getEarliest(books, numOfBooks)]);

	printf("\nTotal pages: %d\n", totalPage(books, numOfBooks));

	printf("\nPrinting the book with ISBN #%d\n", books[2].ISBN);
	printBook(&books[2]);
}

