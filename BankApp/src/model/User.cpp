#include "User.h"

User::User(const LogInData &data) : LogInData(data), id(-1), email("") {}

User::~User() {}
