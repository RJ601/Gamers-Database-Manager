#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Games_played
{
    string game_ID;
    float hours_played;
    int achievements_unlocked;
    Games_played *right;
    Games_played *left;

public:
    Games_played()
    {
        game_ID = "\0";
        hours_played = 0;
        achievements_unlocked = 0;
        right = left = NULL;
    }

    Games_played(string id, float hours, int achievements)
    {
        game_ID = id;
        hours_played = hours;
        achievements_unlocked = achievements;
        right = left = NULL;
    }

    void setGameID(const string& id)
    {
        game_ID = id;
    }

    string getGameID() const
    {
        return game_ID;
    }

    void setHoursPlayed(float hours)
    {
        hours_played = hours;
    }

    float getHoursPlayed() const
    {
        return hours_played;
    }

    void setAchievementsUnlocked(int achievements)
    {
        achievements_unlocked = achievements;
    }

    int getAchievementsUnlocked() const
    {
        return achievements_unlocked;
    }  

    void set_right(Games_played *r)
    {
        right = r;
    }

    void set_left(Games_played *l)
    {
        left = l;
    }

    Games_played* get_right() const
    {
        return right;
    }  

    Games_played* get_left() const
    {
        return left;
    }

    void display()
    {
        cout<<endl<<"Games Played"<<endl;
        cout<<"Game ID: "<<game_ID<<endl;
        cout<<"Hours Played: "<<hours_played<<endl;
        cout<<"Achievements Unlocked: "<<achievements_unlocked<<endl;
        cout<<endl;
    }
};


class Player
{
    string player_ID;
    string name;
    string phone_number;
    string email;
    string password;
    Games_played *games; // a pointer to the root of a tree for the games played by the player - aggregation
    Player *right;
    Player *left;

public:
    Player()
    {
        player_ID = name = phone_number = email = password = "/0";
        games = NULL;
        right = left = NULL;
    }

    Player(string id, string name, string phone, string email, string password)
    {
        player_ID = id;
        this->name = name;
        phone_number = phone;
        this->email = email;
        this->password = password;
        games = NULL;
        right = left = NULL;
    }

    void setPlayerID(const string& id)
    {
        player_ID = id;
    }

    string getPlayerID() const
    {
        return player_ID;
    }

    void setName(const string& name)
    {
        this->name = name;
    }

    string getName() const
    {
        return name;
    }

    void setPhoneNumber(const string& phone)
    {
        phone_number = phone;
    }

    string getPhoneNumber() const
    {
        return phone_number;
    }

    void setEmail(const string& email)
    {
        this->email = email;
    }

    string getEmail() const
    {
        return email;
    }

    void setPassword(const string& password)
    {
        this->password = password;
    }

    string getPassword() const
    {
        return password;
    }

    void setGames(Games_played* g)
    {
        games = g;
    }

    Games_played* getGames() const
    {
        return games;
    }

    void set_right(Player *r)
    {
        right = r;
    }

    void set_left(Player *l)
    {
        left = l;
    }

    Player* get_right() const
    {
        return right;
    }  

    Player* get_left() const
    {
        return left;
    }

    Games_played* insert_games_played(Games_played *root, string id, float hours, int achievements)
    {
        if (root == NULL)
        {
            Games_played *node = new Games_played;
            node->setGameID(id);
            node->setAchievementsUnlocked(achievements);
            node->setHoursPlayed(hours);

            root = node;
            return root;
        }

        if (root->getGameID() < id)
        {
            root->set_right(insert_games_played(root->get_right(), id, hours, achievements));
        }
        else if (root->getGameID() > id)
        {
            root->set_left(insert_games_played(root->get_left(), id, hours, achievements));
        }
        else
        {
            cout<<"Game ID already exists"<<endl;
            // ask if information to be replaced
        }
        return root;
    }

    // delete

    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<player_ID<<endl;
        cout<<"Phone Number: "<<phone_number<<endl;
        cout<<"Email Address: "<<email<<endl;
        cout<<"Password: "<<password<<endl;
        
        // inorder traverse and display games played
        inorder(games);
        cout<<endl;
    }

    void inorder(Games_played *root)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->get_left());
        root->display();
        inorder(root->get_right());
    }
};

class Game
{
    string game_ID;
    string name;
    string publisher;
    string developer;
    float file_size;  // GBs
    int downloads;
    Game *right;
    Game* left;

public:
    Game()
    {
        game_ID = name = publisher = developer = "/0";
        file_size = 0.0f;
        downloads = 0;
        right = left = NULL;
    }

    Game(string id, string name, string publisher, string developer, float file_size, int downloads)
    {
        game_ID = id;
        this->name = name;
        this->publisher = publisher;
        this->developer = developer;
        this->file_size = file_size;
        this->downloads = downloads;
        right = left = NULL;
    }

    void setGameID(const string& id)
    {
        game_ID = id;
    }

    string getGameID() const
    {
        return game_ID;
    }

    void setName(const string& name)
    {
        this->name = name;
    }

    string getName() const
    {
        return name;
    }

    void setPublisher(const string& publisher)
    {
        this->publisher = publisher;
    }

    string getPublisher() const
    {
        return publisher;
    }

    void setDeveloper(const string& developer)
    {
        this->developer = developer;
    }

    string getDeveloper() const
    {
        return developer;
    }

    void setFileSize(float size)
    {
        file_size = size;
    }

    float getFileSize() const
    {
        return file_size;
    }

    void setDownloads(int downloads)
    {
        this->downloads = downloads;
    }

    int getDownloads() const
    {
        return downloads;
    }

    void set_right(Game *r)
    {
        right = r;
    }

    void set_left(Game *l)
    {
        left = l;
    }

    Game* get_right() const
    {
        return right;
    }

    Game* get_left() const
    {
        return left;
    }
};

class Database
{
    Player *players; // bst
    Game *games; // bst

public:
    Database()
    {
        players = NULL;
        games = NULL;
    }

    Database(Player *&p, Game *&g)
    {
        players = p;
        games = g;
    }

    void store()
    {
        // generate seed
        int seed = 230137;
        int temp = (seed%100)*10 + 100;

        // players
        // open csv file and start reading
        fstream file;
        file.open("Players.txt");
        if (!file)
        {
            cout<<"Could not open file"<<endl;
            return;
        }

        string line;
        while (getline(file, line))
        {
            // generate random number between 0-1000
            int num = rand()%1001;

            // whenever you come across a line that is to be inserted
            if (num >= temp)
            {
                // assign variables and call insert player
                int count = 0;

                string id, name, phone, email, password;

                while (line[count] != ',')
                {
                    id += line[count];
                    count++;
                }
                count++;

                while (line[count] != ',')
                {
                    name += line[count];
                    count++;
                }
                count++;

                while (line[count] != ',')
                {
                    phone += line[count];
                    count++;
                }
                count++;

                while (line[count] != ',')
                {
                    email += line[count];
                    count++;
                }
                count++;

                while (line[count] != ',')
                {
                    password += line[count];
                    count++;
                }
                count++;

                Player *node = new Player(id, name, phone, email, password);

                while (line[count] != '\0')
                {
                    // games played in loop - insert - bst
                    string game_id = "\0";
                    string hours = "\0";
                    string achievements = "\0";
                    
                    while ((line[count] != ',') && (line[count] != '\0'))
                    {
                        game_id += line[count];
                        count++;
                    }

                    if (line[count] == ',')
                    {
                        count++;
                    }

                    while ((line[count] != ',') && (line[count] != '\0'))
                    {
                        hours += line[count];
                        count++;
                    }

                    if (line[count] == ',')
                    {
                        count++;
                    }

                    while ((line[count] != ',') && (line[count] != '\0'))
                    {
                        achievements += line[count];
                        count++;
                    }

                    if (line[count] == ',')
                    {
                        count++;
                    }

                    float h = stof(hours); 
                    int a = stoi(achievements);
                    node->setGames(node->insert_games_played(node->getGames(), game_id, h, a));
                }

                // insert function call
                players = insert_player(players, node);
            }
        }

        file.close();

        // create a new file and store the players database there
        file.open("Players_Databse.csv", ios::out);
        // inorder traversal and store
        inorder_store(players, file);
        file.close();

        // games
        file.open("Games.txt");
        // open csv file and start reading
        if (!file)
        {
            cout<<"Could not open file"<<endl;
            return;
        }

        while (getline(file, line))
        {
            int count = 0;

            while (line[count] != '\0')
            {
                string id = "\0", name = "\0", publisher = "\0", developer = "\0", file_size = "\0", downloads = "\0";

                while ((line[count] != ',') && (line[count] != '\0'))
                {
                    id += line[count];
                    count++;
                }

                if (line[count] == ',')
                {
                    count++;
                }

                while ((line[count] != ',') && (line[count] != '\0'))
                {
                    name += line[count];
                    count++;
                }

                if (line[count] == ',')
                {
                    count++;
                }

                while ((line[count] != ',') && (line[count] != '\0'))
                {
                    developer += line[count];
                    count++;
                }

                if (line[count] == ',')
                {
                    count++;
                }

                while ((line[count] != ',') && (line[count] != '\0'))
                {
                    publisher += line[count];
                    count++;
                }

                if (line[count] == ',')
                {
                    count++;
                }

                while ((line[count] != ',') && (line[count] != '\0'))
                {
                    file_size += line[count];
                    count++;
                }

                if (line[count] == ',')
                {
                    count++;
                }

                while ((line[count] != ',') && (line[count] != '\0'))
                {
                    downloads += line[count];
                    count++;
                }

                if (line[count] == ',')
                {
                    count++;
                }

                // make object
                float f = stof(file_size);
                int d = stoi(downloads);

                Game *node = new Game(id, name, publisher, developer, f, d);
                games = insert_game(games, node);
            }
        }

        file.close();

        // file
        file.open("Games_Database.csv", ios::out);
        // inorder store
        inorder_store_games(games, file);

        file.close();
    }

    void inorder_store_games(Game* root, fstream &file)
    {
        if (root == NULL)
        {
            return;
        }

        inorder_store_games(root->get_left(), file);

        // store root
        file<<root->getGameID()<<',';
        file<<root->getName()<<',';
        file<<root->getDeveloper()<<',';
        file<<root->getPublisher()<<',';
        file<<root->getFileSize()<<',';
        file<<root->getDownloads()<<',';
        file<<'\n';

        inorder_store_games(root->get_right(), file);
    }

    void inorder_store(Player *root, fstream &file)
    {
        if (root == NULL)
        {
            return;
        }

        inorder_store(root->get_left(), file);

        // store root
        file<<root->getPlayerID()<<',';
        file<<root->getName()<<',';
        file<<root->getPhoneNumber()<<',';
        file<<root->getEmail()<<',';
        file<<root->getPassword()<<',';

        // games played - inorder display
        inorder_games_played(root->getGames(), file);

        file<<"\n";

        inorder_store(root->get_right(), file);
    }

    void inorder_games_played(Games_played *root, fstream &file)
    {
        if (root == NULL)
        {
            return;
        }

        inorder_games_played(root->get_left(), file);

        file<<root->getGameID()<<',';
        file<<root->getHoursPlayed()<<',';
        file<<root->getAchievementsUnlocked()<<',';
        
        inorder_games_played(root->get_right(), file);
    }

    Game* insert_game(Game *root, Game *&node)
    {
        if (root == NULL)
        {
            root = node;
            cout<<root->getGameID()<<endl;
            return root;
        }

        if (root->getGameID() < node->getGameID())
        {
            root->set_right(insert_game(root->get_right(), node));
        }
        else if (root->getGameID() > node->getGameID())
        {
            root->set_left(insert_game(root->get_left(), node));
        }
        else
        {
            cout<<"ID already exists"<<endl;
            delete node;
        }

        return root;
    }

    Player* insert_player(Player *root, Player *&node) // a whole row with id, email... password, games - make a separate tree for games played
    {
        if (root == NULL)
        {
            root = node;
            return root;
        }

        if (root->getPlayerID() < node->getPlayerID())
        {
            root->set_right(insert_player(root->get_right(), node));
        }
        else if (root->getPlayerID() > node->getPlayerID())
        {
            root->set_left(insert_player(root->get_left(), node));
        }
        else
        {
            cout<<"ID already exists"<<endl;
            delete node;
        }

        return root;
    }

    void delete_game()
    {

    }

    void delete_player()
    {

    }

    void display_players() // inorder
    {
        inorder(players);
    }

    void inorder(Player *root)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->get_left());
        root->display();
        inorder(root->get_right());
    }
};

int main()
{
    Database database;
    database.store();
    //database.display_players();
}