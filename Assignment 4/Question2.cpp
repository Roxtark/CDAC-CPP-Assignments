#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Texture {
private:
    string name;
    int width;
    int height;

public:
    Texture(string name, int width, int height) {
        this->name = name;
        this->width = width;
        this->height = height;

        cout << "[Texture Loaded]" << endl;
    }

    ~Texture() {
        cout << "[Texture Released]" << endl;
    }

    void display() const {
        cout << "Texture: " << name << endl;
        cout << "Dimensions: " << width << " x " << height << endl;
    }
};

class Shader {
private:
    string name;
    string type;

public:
    Shader(string name, string type) {
        this->name = name;
        this->type = type;

        cout << "[Shader Compiled]" << endl;
    }

    ~Shader() {
        cout << "[Shader Destroyed]" << endl;
    }

    int getReferenceCount(shared_ptr<Shader> shader) {
        return shader.use_count();
    }
};

class AudioClip {
private:
    string name;
    double duration;

public:
    AudioClip(string name, double duration) {
        this->name = name;
        this->duration = duration;
    }

    string getName() {
        return name;
    }
};

int main() {
    auto tex1 = make_unique<Texture>("player_sprite", 512, 512);

    tex1->display();

    // unique_ptr<Texture> tex2 = tex1; // Copying a unique_ptr is not allowed because it has exclusive ownership.

    unique_ptr<Texture> tex2 = move(tex1);

    cout << "tex1 is null: " << (tex1 == nullptr ? "YES" : "NO") << endl;

    cout << endl;

    auto shader = make_shared<Shader>("main_vert", "vertex");

    cout << "Ref count: " << shader.use_count() << endl;

    {
        auto rendererRef = shader;

        cout << "Ref count: " << shader.use_count() << endl;

        auto editorRef = shader;

        cout << "Ref count: " << shader.use_count() << endl;
    }

    cout << "Ref count: " << shader.use_count() << endl;

    cout << endl;

    auto audio = make_shared<AudioClip>("explosion", 3.5);

    weak_ptr<AudioClip> observer = audio;

    if (auto clip = observer.lock())
        cout << "Clip alive: " << clip->getName() << endl;

    audio.reset();

    if (observer.expired())
        cout << "Clip already unloaded." << endl;

    return 0;
}
