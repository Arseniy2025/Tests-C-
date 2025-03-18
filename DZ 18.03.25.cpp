#include <iostream>
#include <string>
using namespace std;

class User {
public:
    int id;
    string name;
    string email;
public:
    User(int id, string name, string email) {
        this->id = id;
        this->name = name;
        this->email = email;
    }
    int getID() { return id; }
    string getName() { return name; }
    string getEmail() { return email; }

    void setName(string& newname) {
        name=newname;
    }
    void setEmail(string& newemail) {
        name = newemail;
    }

    virtual void Info() {
        cout << "ID " << id << ", Имя " << name << ", Почта " << email<<endl;
    }
};

class Admin :public User {
public:
    Admin(int id, string name, string& email) : User(id,name,email) {
        this->id = id;
        this->name = name;
        this->email = email;
    }
    void deletePost(int postID) {
        cout << "Пост с Id " << postID << "был удален админом " << name << endl;
    }

    void banUser(User* user) {
        cout << "Пользователь " << user << "был забанен админом " << name << endl;
    }
};

class Post {
private:
    int id;
    User* author;
    string content;
    string time;
public:
    Post(int id, User* author, string content, string time) {
        this->id = id;
        this->author = author;
        this->content = content;
        this->time = time;
    }

    int getID() {
        return id;
    }
    User* getAuthor() {
        return author;
    }
    string getContent() {
        return content;
    }
    string getTime() {
        return time;
    }
   
    void setContent(string newContent) {
        content = newContent;
    }

    void Info() {
        cout << "Пост с ID " << id << ", Автор " << author->getName() << ", Контент " << content << ", Время " << time << endl;
    }
};

class Comment {
private:
    int id;
    User* author;
    Post* post;
    string content;
    string time;
public:
    Comment(int id, User* author, Post* post, string content, string time) {
        this->id = id;
        this->author = author;
        this->post = post;
        this->content = content;
        this->time = time;
    }
    int getID() {
        return id;
    }
    User* getAuthor() {
        return author;
    }
    Post* getPost() {
        return post;
    }
    string getContent() {
        return content;
    }
    string getTime() {
        return time;
    }

    void setContent(string newContent) {
        content = newContent;
    }

    void Info() {
        cout << "Комментарий с ID " << id << ", Автор " << author->getName() << ", Контент " << content << ", Время " << time << endl;
    }
};

class Like {
private:
    int id;
    User* author;
    Post* post;
public:
    Like(int id, User* author, Post* post) {
        this->id = id;
        this->author = author;
        this->post = post;
    }
    int getID() {
        return id;
    }
    User* getAuthor() {
        return author;
    }
    Post* getPost() {
        return post;
    }
    void Info() {
        cout << "Лайк с ID " << id << ", Пользователь " << author->getName() << ", Пост " << post->getContent() << endl;
    }
};

class Comunity {
private:
    int id;
    string name;
    User* creator;
    static const int member = 10;
    User* members[member];
    int member_count;
public:
    Comunity(int id, string name, User* creator) {
        this->id = id;
        this->name = name;
        this->creator = creator;
        this->member_count = 0;
    }

    int getID() {
        return id;
    }
    string getName() {
        return name;
    }
    User* getCreator() {
        return creator;
    }

    void addMember(User* user) {
        if(member_count < member) {
            members[member_count++] = user;
        }
        else {
        cout << "Сообщество полное!" << endl;
        }
    }

    void Info() {
        cout << " Сообщество ID: " << id << ", Имя: " << name << ", Создатель: " << creator->getName() << endl;
        cout << "Сообщение: ";
        for (int i = 0; i < member_count; ++i) {
            cout << members[i]<< " ";
        }
        cout << endl;
    }
};


int main() {
    setlocale(LC_ALL, "rus");

    string name1 = "Алан";
    string email1 = "alan@example";
    User user1(1, name1, email1);

    string name2 = "Гордон";
    string email2 = "gordon@example";
    User admin1(2, name2, email2);

    string postContent = "Просто пост";
    string postTime = "18.03.25 , 11:00";
    Post post1(1, &user1, postContent, postTime);
    
    string commentContent = "Отличный пост!";
    string commentTime = "18.03.25 , 11:10";
    Comment comment1(1, &admin1, &post1, commentContent, commentTime);

    string communityName = "C++";
    Comunity community1(1, communityName, &user1);

    Like like1(1, &user1, &post1);

    user1.Info();
    admin1.Info();
    post1.Info();
    comment1.Info();
    community1.Info();
    like1.Info();

}



