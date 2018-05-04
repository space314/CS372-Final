#include "User.h"

int NonWizard::get_lvl() const { return m_level; }

int LowLevelWizard::get_lvl() const{ return m_level; }

int HighLevelWizard::get_lvl() const { return m_level; }

int God::get_lvl() const { return m_level; }