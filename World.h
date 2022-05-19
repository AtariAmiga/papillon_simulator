struct World {
    char* name;
};

struct World* World_new(char* name);
void World_println(struct World* this);

