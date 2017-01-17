Sub ConvertCellsToNumeric()
	' Range of columns
    For col = 11 To 12:
        Dim i As Integer
        
        ' Row to start from 
        i = 10
  
        Do While ActiveSheet.Cells(i, col).Value <> ""
            ActiveSheet.Cells(i, col).Select
            
            With ActiveCell
                .Value = CDbl(.Value)
            End With
            
            i = i + 1
        Loop
    Next col
End Sub