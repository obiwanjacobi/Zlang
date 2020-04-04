#pragma once

#include "../AST/AstExpression.h"

std::string ToString(AstExpressionOperator op);
std::string ToString(std::shared_ptr<AstNumeric> numeric);
std::string ToString(std::shared_ptr<AstExpression> expression);
std::string ToString(std::shared_ptr<AstExpressionOperand> expression);