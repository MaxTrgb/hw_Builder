#include <iostream>
#include <string>

using namespace std;

class MessageBuilder {
public:
    virtual void buildSubject(const string& subject) = 0;
    virtual void buildBody(const string& body) = 0;
    virtual void buildRecipient(const string& recipient) = 0;
    virtual string getMessage() = 0;
};

class TextMessageBuilder : public MessageBuilder {
private:
    string subject;
    string body;
    string recipient;

public:
    void buildSubject(const string& subject) override {
        this->subject = subject;
    }

    void buildBody(const string& body) override {
        this->body = body;
    }

    void buildRecipient(const string& recipient) override {
        this->recipient = recipient;
    }

    string getMessage() override {
        return "Text Message:\nSubject: " + subject + "\nRecipient: " + recipient + "\nBody: " + body;
    }
};

class EmailMessageBuilder : public MessageBuilder {
private:
    string subject;
    string body;
    string recipient;

public:
    void buildSubject(const string& subject) override {
        this->subject = subject;
    }

    void buildBody(const string& body) override {
        this->body = body;
    }

    void buildRecipient(const string& recipient) override {
        this->recipient = recipient;
    }

    string getMessage() override {
        return "Email Message:\nSubject: " + subject + "\nRecipient: " + recipient + "\nBody: " + body;
    }
};

class MessageDirector {
private:
    MessageBuilder* builder;

public:
    MessageDirector(MessageBuilder* builder) {
        this->builder = builder;
    }

    void constructMessage(const string& subject, const string& body, const string& recipient) {
        builder->buildSubject(subject);
        builder->buildBody(body);
        builder->buildRecipient(recipient);
    }
};

int main() {
    TextMessageBuilder textMessageBuilder;
    MessageDirector textMessageDirector(&textMessageBuilder);

    textMessageDirector.constructMessage("Hello", "Message text.", "Name");
    cout << textMessageBuilder.getMessage() << endl;

    EmailMessageBuilder emailMessageBuilder;
    MessageDirector emailMessageDirector(&emailMessageBuilder);

    emailMessageDirector.constructMessage("Hi", "Message text.", "Name");
    cout << emailMessageBuilder.getMessage() << endl;

    return 0;
}

