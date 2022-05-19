struct Emitter {
    char* name;
};

struct Emitter* Emitter_new(char* name);
void Emitter_print(struct Emitter* this);

