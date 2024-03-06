package RefactoredMovieCode;

class NewRelease extends Price{
    int getPriceCode(){
        return Movie.NEW_RELEASE;
    }

    double getCharge(int daysRented){
        return daysRented * 3;
    }
}


// public class NewRelease {
    
// }
