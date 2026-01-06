  //////////testing/////////////////////////
  printf("-----------beffor: -----------\n");

  printf("stack a: \n");
  print_stack(stack_a);

  printf("stack b: \n");
  print_stack(stack_b);

  printf("----------------------\n");

  push_a_to_b(stack_a, stack_b);
  push_a_to_b(stack_a, stack_b);
  push_a_to_b(stack_a, stack_b);
  push_a_to_b(stack_a, stack_b);
  printf("----------------------\n");

  printf("stack a: \n");
  print_stack(stack_a);
  printf("stack b: \n");
  print_stack(stack_b);
  printf("----------------------\n");

  reverse_rotate_a(stack_a);
  reverse_rotate_b(stack_b);
  printf("stack a: \n");
  print_stack(stack_a);
  printf("stack b: \n");
  print_stack(stack_b);

  reverse_rotate_a_b(stack_a, stack_b);

  printf("----------------------\n");
  printf("-----------after: -----------\n");
  printf("stack a: \n");
  print_stack(stack_a);
  printf("stack b: \n");
  print_stack(stack_b);
  ///////////////////////////////////////////////
