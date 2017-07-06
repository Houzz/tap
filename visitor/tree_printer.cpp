/*
Copyright 2017 Houzz, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "tree_printer.h"
#include "ast/simple_variable.h"
#include "ast/simple_function_call.h"
#include "ast/scalar_expression.h"
#include "ast/constant_expression.h"
#include "ast/class_constant_expression.h"
#include <cstdio>

Tap::TreePrinter::TreePrinter()
{
}

Tap::TreePrinter::~TreePrinter()
{
}

void Tap::TreePrinter::visit(HPHP::AssignmentExpression* e)
{
  printf("assignment\n");
}
void Tap::TreePrinter::visit(HPHP::BlockStatement* e)
{
  printf("block statement\n");
}
void Tap::TreePrinter::visit(HPHP::BreakStatement* e)
{
  printf("break statement\n");
}
void Tap::TreePrinter::visit(HPHP::CaseStatement* e)
{
  printf("case statement\n");
}
void Tap::TreePrinter::visit(HPHP::ClassConstantStatement* e)
{
  printf("class constant statement\n");
}
void Tap::TreePrinter::visit(HPHP::ClassStatement* e)
{
  printf("class statement\n");
}
void Tap::TreePrinter::visit(HPHP::ClassVariableStatement* e)
{
  printf("class variable statement\n");
}
void Tap::TreePrinter::visit(HPHP::ClassConstantExpression* e) {
  printf("class constant expression: varName: %s\n", e->getVarName().c_str());
}
void Tap::TreePrinter::visit(HPHP::ConstantExpression* e)
{
  printf("constant expression, name: %s\n", e->getName().c_str());
}
void Tap::TreePrinter::visit(HPHP::ContinueStatement* e)
{
}
void Tap::TreePrinter::visit(HPHP::DoStatement* e)
{
}
void Tap::TreePrinter::visit(HPHP::ExpStatement* e)
{
}
void Tap::TreePrinter::visit(HPHP::ExpressionList* e)
{
}
void Tap::TreePrinter::visit(HPHP::ForEachStatement* e)
{
}
void Tap::TreePrinter::visit(HPHP::ForStatement* e)
{
}
void Tap::TreePrinter::visit(HPHP::FunctionStatement* e) {
  printf("function statement\n");
}
void Tap::TreePrinter::visit(HPHP::IfBranchStatement* e) {
  printf("if branch statement\n");
}
void Tap::TreePrinter::visit(HPHP::IfStatement* e) {
  printf("if statement\n");
}
void Tap::TreePrinter::visit(HPHP::InterfaceStatement* e) {
  printf("interface statement\n");
}
void Tap::TreePrinter::visit(HPHP::MethodStatement* e) {
  printf("method statement\n");
}
void Tap::TreePrinter::visit(HPHP::ModifierExpression* e)
{
}
void Tap::TreePrinter::visit(HPHP::ParameterExpression* e)
{
}
void Tap::TreePrinter::visit(HPHP::ReturnStatement* e) {
  printf("return statement\n");
}
void Tap::TreePrinter::visit(HPHP::SimpleVariable* e) {
  printf("simple variable: %s\n", e->getName().c_str());
}
void Tap::TreePrinter::visit(HPHP::StatementList* e) {
  printf("statement list\n");
}
void Tap::TreePrinter::visit(HPHP::SwitchStatement* e) {
  printf("switch statement\n");
}
void Tap::TreePrinter::visit(HPHP::WhileStatement* e) {
  printf("while statement\n");
}
void Tap::TreePrinter::visit(HPHP::SimpleFunctionCall* e) {
  printf("Simple function call, func name: %s\n", e->getName().c_str());
}
void Tap::TreePrinter::visit(HPHP::ScalarExpression* e) {
  printf("Scalar expression, type: %d\n", e->getScalarType());
}