#ifndef THEME_H
#define THEME_H


class Theme
{
    public:
        Theme();
        void ClearScreen();
        void showLoadingAnimation();
        virtual ~Theme();

    protected:

    private:

    // Splitting Varible
    char loadingCharacter = 219;
    char passCharacter = 'o';
};

#endif // THEME_H
