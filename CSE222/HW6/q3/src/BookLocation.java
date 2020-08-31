/**
 * BookLocation is a data class that stores location of a book in library
 */
public class BookLocation {
    private final int corridor;
    private final int shelf;
    private final int shelfIndex;

    BookLocation(int corridor, int shelf, int shelfIndex) {
        this.corridor = corridor;
        this.shelf = shelf;
        this.shelfIndex = shelfIndex;
    }

    @Override
    public String toString() {
        return String.format("c%ds%d.%d", corridor, shelf, shelfIndex);
    }
}