#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{ int i = 1;
  string quotes[] = {
        "Believe you can and you're halfway there.",
        "Push yourself, because no one else is going to do it for you.",
        "Failure is the opportunity to begin again more intelligently.",
        "Success doesn’t just find you. You have to go out and get it.",
        "Dream it. Wish it. Do it.",
        "It’s going to be hard, but hard does not mean impossible.",
        "Don’t stop when you’re tired. Stop when you’re done.",
        "Wake up with determination. Go to bed with satisfaction.",
        "Do something today that your future self will thank you for.",
        "Little things make big days.",
        "It’s not whether you get knocked down, it’s whether you get up.",
        "The harder you work for something, the greater you’ll feel when you achieve it.",
        "Dream bigger. Do bigger.",
        "Don’t wait for opportunity. Create it.",
        "Sometimes we’re tested not to show our weaknesses, but to discover our strengths.",
        "The key to success is to focus on goals, not obstacles.",
        "Keep going. Everything you need will come to you at the perfect time.",
        "You are capable of amazing things.",
        "Difficult roads often lead to beautiful destinations.",
        "Don’t limit your challenges. Challenge your limits.",
        "No pressure, no diamonds.",
        "Stay focused and never give up.",
        "You don’t have to be great to start, but you have to start to be great.",
        "The only limit to our realization of tomorrow is our doubts of today.",
        "Act as if what you do makes a difference. It does.",
        "Start where you are. Use what you have. Do what you can.",
        "If you want to achieve greatness, stop asking for permission.",
        "Success is not in what you have, but who you are.",
        "What lies behind us and what lies before us are tiny matters compared to what lies within us.",
        "Do what you can, with what you have, where you are.",
        "Opportunities don’t happen. You create them.",
        "Set your goals high, and don’t stop till you get there.",
        "Doubt kills more dreams than failure ever will.",
        "Success is what happens after you have survived all your mistakes.",
        "The only place where success comes before work is in the dictionary.",
        "You get what you work for, not what you wish for.",
        "The expert in anything was once a beginner.",
        "The way to get started is to quit talking and begin doing.",
        "Everything you’ve ever wanted is on the other side of fear.",
        "You are braver than you believe, stronger than you seem, and smarter than you think.",
        "Nothing is impossible. The word itself says 'I'm possible!'",
        "Your limitation—it’s only your imagination.",
        "Hardships often prepare ordinary people for an extraordinary destiny.",
        "Be so good they can’t ignore you.",
        "Winners never quit, and quitters never win.",
        "Success is not the key to happiness. Happiness is the key to success.",
        "Go confidently in the direction of your dreams.",
        "Happiness is not something ready-made. It comes from your own actions.",
        "It does not matter how slowly you go as long as you do not stop.",
        "If you can dream it, you can do it.",
        "The secret of getting ahead is getting started.",
        "Keep your face always toward the sunshine, and shadows will fall behind you.",
        "Perseverance is not a long race; it is many short races one after the other.",
        "Live as if you were to die tomorrow. Learn as if you were to live forever.",
        "Do what you love, and you’ll never work a day in your life.",
        "The best way to predict the future is to create it.",
        "You must expect great things of yourself before you can do them.",
        "Life is 10% what happens to us and 90% how we react to it.",
        "A journey of a thousand miles begins with a single step.",
        "Success isn’t overnight. It’s when every day you get a little better than before.",
        "You miss 100% of the shots you don’t take.",
        "Learn from yesterday, live for today, hope for tomorrow.",
        "Don’t let what you cannot do interfere with what you can do.",
        "When you feel like quitting, think about why you started.",
        "If you want something you never had, you have to do something you’ve never done.",
        "Sometimes later becomes never. Do it now.",
        "Don’t wish for it. Work for it.",
        "The only way to do great work is to love what you do.",
        "Failure is not the opposite of success; it’s part of success.",
        "You have to fight through some bad days to earn the best days of your life.",
        "There is no elevator to success. You have to take the stairs.",
        "Do the hard jobs first. The easy jobs will take care of themselves.",
        "Challenges are what make life interesting, and overcoming them is what makes life meaningful.",
        "The best revenge is massive success.",
        "If you are not willing to risk the usual, you will have to settle for the ordinary.",
        "The best view comes after the hardest climb.",
        "If opportunity doesn’t knock, build a door.",
        "You don’t always get what you wish for; you get what you work for.",
        "You must do the thing you think you cannot do.",
        "Never bend your head. Always hold it high. Look the world straight in the eye.",
        "You were born to be a player. You were meant to be here. This moment is yours.",
        "Make each day your masterpiece.",
        "Act like what you do makes a difference. It does.",
        "The only thing standing between you and your goal is the story you keep telling yourself as to why you can’t achieve it.",
        "You are never too old to set another goal or to dream a new dream.",
        "Don’t watch the clock; do what it does. Keep going.",
        "A year from now, you may wish you had started today.",
        "Motivation is what gets you started. Habit is what keeps you going.",
        "Do or do not. There is no try.",
        "I find that the harder I work, the more luck I seem to have.",
        "Be stronger than your excuses.",
        "You only fail when you stop trying.",
        "Don’t be pushed around by the fears in your mind. Be led by the dreams in your heart."
    };
    while (quotes) {
    int size = sizeof(quotes) / sizeof(quotes[0]);
    srand(time(0));
    int randomIndex = rand() % size;
    string next;

    cout << i << ". Random Motivational Quote: " << quotes[randomIndex]<< endl;
    cin >> next;
    i++;
   }

    return 0;
}
