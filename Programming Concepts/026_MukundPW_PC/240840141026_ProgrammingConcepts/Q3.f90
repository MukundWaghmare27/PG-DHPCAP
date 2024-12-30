program search_numbers
  integer :: numbers(10)
  integer :: i, search_number

  print *, 'Enter 10 numbers:'
  do i = 1, 10
     read *, numbers(i)
  end do

  ! Accept the number to search
  print *, 'Enter a number to search:'
  read *, search_number

  ! Display numbers greater than the search number
  print *, 'Numbers greater than ', search_number, ' are:'
  do i = 1, 10
     if (numbers(i) > search_number) then
        write(*, '(I4)', advance="no") numbers(i)
        write(*, '(A)', advance="no") ', '
     end if
  end do
  print *  
end program search_numbers


