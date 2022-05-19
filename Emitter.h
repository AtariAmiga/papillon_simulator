struct Emitter {
    char* name;
};

struct Emitter* Emitter_new(char* name);
void Emitter_println(struct Emitter* this);

